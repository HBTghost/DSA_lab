#include "Examinee.h"

int main(int argc, char const *argv[])
{
    std::string test { "BD1200002,,7.0,6.25,6.0,6.25,6.5,,,,,,5.2,N1,BinhDinh" };
    Examinee res { ReadExaminee(test) };
    info(res);
    
    return 0;
}