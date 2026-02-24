#include <iostream>
#include <string>

#include "color_print.h"
#include "onnx_graph.h"

//protoc --decode=onnx.ModelProto ONNX_files/proto/onnx.proto3 < ONNX_files/mobilenetv2-7.onnx > ONNX_files/test_1.txt


int main ()
{
    //long password = 0;
    //set_color (GREEN, NORMAL, WHITE_B);
    //std::cout << "Begin" << 4  << std::endl;
    //set_color ();
    //std::cout << "Begin" << 4  << std::endl;
    //std::cin >> password; 


    operator_set_id_t model_1;  
    model_1.print_inf ("");

    operator_set_id_t model_2;
    model_2.set_all_parameters (10, "Hello!");
    model_2.print_inf ("model_2");

    

    return 0;
}