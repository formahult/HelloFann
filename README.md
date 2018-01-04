# HelloFann
Hand written firgure recognition artificial neural network built for the canonical Hello World of ANNs: the MNIST data set. Accuracy hovers around 90% in the current form. This was implemented as an initial stage to do other forms of character recognition.

# Dependecies
- OpenCV3 https://opencv.org/
Not entirely necessary, but makes viewing the figures easier if desired. I use OpenCV in further more complex character recognitionprojects.
- Fast Artificial Neural Network (FANN) library http://yann.lecun.com/exdb/mnist/

# Building
Basic makefile will build the various components
- Make GenerateTrainingFile
- Make TrainFann
- Make TestFann

# Running
Process data and generate a file to train FANN. The MNIST handwritten data set this was built for can be found at http://yann.lecun.com/exdb/mnist/
Your own data could certainly be substituted.
- ./GenerateTrainingFile [Labels.idx1] [ImageData.idx3] [OutputFileName.txt]
Train FANN
- ./TrainFann [TrainingData.txt] [savedANN.net]
Test and run FANN. There are separate test sets to check that FANN is working correctly
- ./TestFann [Labels.idx1] [ImageData.idx3] [savedANN.net]
