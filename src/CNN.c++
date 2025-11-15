#include "CNN.h++"
#include "matrix.h++"

using namespace std;
using namespace matrix;
class Layer {

};

class ConvolutionLayer : Layer {
    private:
    Matrix<float> kernel;
    vector<float> layerInput;

    public:
    ConvolutionLayer(Matrix<float> &initialKernel) {
        this->kernel = initialKernel;
    }


};

class FullyConnectedLayer : Layer {
    private:
    vector<float> weights;
    vector<float> biases;
    float (*activation_function)(float);

    //For backpropagation
    vector<float> layerInput; 
    vector<float> preactivationOutput;

    public:
    FullyConnectedLayer(float (*activation_function)(float), vector<float> &initialWeights, vector<float> &initialBiases) {
        this->activation_function = activation_function;
        this->weights = initialWeights;
        this->weights = initialBiases;
    }


    Matrix<float> evaluate_layer(Matrix<float> &input) {
        
        return;
    }
};

class CNN {
    private:
    vector<Layer> layers;

    public:

};
