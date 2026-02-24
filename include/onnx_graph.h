#ifndef ONNX_GRAPH_H_
#define ONNX_GRAPH_H_

#include <string>

#include "color_print.h"

class operator_set_id_t
{
    //--------------------------------------
    private:

        u_int64_t   value;
        std::string domain;

    //--------------------------------------
    public:

        operator_set_id_t () : value(0), domain("") {}

        void set_value  (u_int64_t    new_value)  {value  = new_value;}
        void set_domain (std::string& new_domain) {domain = new_domain;}
        void set_all_parameters (u_int64_t new_value = 0, std::string new_domain = "");

        void print_inf (std::string name_object)
        {
            print_line ();

            if (! name_object.empty ())
            {
                set_color (WHITE, BOLD);
                std::cout << name_object << ":\n\n";  
                set_color ();
            }

            std::cout << "value  = " << value  << std::endl;
            std::cout << "domain = " << domain << std::endl;

            print_line ();
        }
};

inline void operator_set_id_t::set_all_parameters (u_int64_t new_value, std::string new_domain)
{
    set_value  (new_value);
    set_domain (new_domain);
}

// inline void operator_set_id_t::print_inf (std::string name_object)
// {
//     print_line ();

//     if (! name_object.empty ())
//     {
//         set_color (WHITE, BOLD);
//         std::cout << name_object << ":\n\n";  
//         set_color ();
//     }

//     std::cout << "value  = " << value;
//     std::cout << "domain = " << value;

//     print_line ();
//}

//--------------------------------------------------------------------------

class model_t 
{
    //---------------------------------------
    private:

    u_int64_t ir_version;
    operator_set_id_t opset_import; 

    //---------------------------------------
    public:
    
};

#endif