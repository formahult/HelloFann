//trainnn.c
//g++ trainnn.cpp -L ../lib -I ../include -lfann -lm -o trainnn
/* Advice for future me:
  Sigmoid activation function likes standardised input data:
    i.e subtract mean and divide by RANGE
  use floats, everythin worksout easier in the end.
*/
#include "fann.h"

int main(int argc, char* argv[]){
  if(argc < 3){
    printf("Usage: TrainFann [infile] [outfile]\n");
    return -1;
  }
    const unsigned int num_input = 784;
    const unsigned int num_output = 10;
    const unsigned int num_layers = 4; //includes in and out layers
    const unsigned int num_neurons_hidden = 16;
    const float desired_error = (const float) 0.005;
    const unsigned int max_epochs = 500000;
    const unsigned int epochs_between_reports = 10;

    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);


    fann_train_on_file(ann, argv[1], max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, argv[2]);

    fann_destroy(ann);

    return 0;
}
