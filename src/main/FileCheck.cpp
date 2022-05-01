#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <experimental/filesystem>
#include <string.h>
/* these are just small things that will be written into a file later on 
and some will be read by the main python script */
bool isVerbose = false;
bool isWrite = false;
bool isempty(std::ifstream& pFile)
    {
    return pFile.peek() == std::ifstream::traits_type::eof();
    }
/*this is the main script*/
int main(int argc,char * argv[])
{   
    auto path = std::string(argv[0]).erase(std::string(argv[0]).length()-3);/*This simply set the path */
    std::experimental::filesystem::current_path(path);
    std::cout << "Current ID: " << argv << std::endl;
    for(int i = 1; i<argc; i++)
    {
        if(std::string(argv[i]) == "-v")
        {
            isVerbose = true;
        }
        else if(std::string(argv[i]) == "-w")
        {
            isWrite = true;
        }
    }
    if(isVerbose == true)
    {
        std::cout << "this just checks if all the files are in place\n PATH: " << std::experimental::filesystem::current_path() << std::endl; 
    }   
    struct stat info;
	const char* pathname = "../ver";
if( stat( pathname, &info ) != 0 )
    {
        std::cout << "Error File Failure: ../ver" << std::endl;
    }
else if( info.st_mode & S_IFDIR )
    {
    if(isVerbose == true)
        {
            std::cout << "OK: ../ver is active " << std::endl; 
        } 
    }
else
    {
        std::cout << "Error File Failure: ../ver" << std::endl;
    }
    return 0;
}
