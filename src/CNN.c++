#include "CNN.h++"


using namespace std;

typedef struct Layer {
    // Z = WX + B
    vector<float> weights;
    vector<float> biases;
    float (*activationFunction)(float);
} Layer;


class CNN {
    private:


    public:

};
