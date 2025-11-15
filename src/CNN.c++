#include "CNN.h++"
#include "matrix.h++"

using namespace std;
using namespace matrix;
class Layer {
    protected:
    float (*ActivationFunction)(float);

    Matrix<float> layerInput;
    Matrix<float> preActivationOutput;

    public:
    virtual void evaluate_layer(Matrix<float> &nextLayerInput) = 0;
    virtual ~Layer() = default;
};

class ConvolutionLayer : public Layer {
    private:
    Matrix<float> kernel;
    float bias = 0;

    public:
    ConvolutionLayer(size_t kernelRows, size_t kernelCols, float (*ActivationFunction)(float)) {
        this->kernel = Matrix<float>(kernelRows, kernelCols);
        this->kernel.kaming_uniform_initialisation(kernelRows * kernelCols);
        
        this->ActivationFunction = ActivationFunction;
        return;
    }
    
    void evaluate_layer(Matrix<float> &nextLayerInput) override {
        //Z = W * X + B
        //O = act(Z);
        this->preActivationOutput = this->layerInput.convolve(this->kernel);
        this->preActivationOutput.bias(this->bias);

        nextLayerInput.set(preActivationOutput.activate(ActivationFunction));
        return;
    }
};

class FullyConnectedLayer : public Layer {
    private:
    Matrix<float> weights;
    Matrix<float> biases;

    public:
    FullyConnectedLayer(size_t previousNumLayers, size_t currentNumLayers, float (*ActivationFunction)(float)) {
        this->weights = Matrix<float>(currentNumLayers, previousNumLayers);
        this->weights.kaming_uniform_initialisation(currentNumLayers);
        this->biases = Matrix<float>(currentNumLayers, 1);
        this->biases.kaming_uniform_initialisation(currentNumLayers);

        this->ActivationFunction = ActivationFunction;
        return;
    }

    void evaluate_layer(Matrix<float> &nextLayerInput) override {
        //Z = W * X + B
        //O = act(Z);
        this->preActivationOutput = this->weights * this->layerInput;
        this->preActivationOutput = this->preActivationOutput + this->biases;

        nextLayerInput.set(preActivationOutput.activate(ActivationFunction));
        return;
    }
};

class CNN {
    private:
    vector<Layer*> layers;

    public:

};
