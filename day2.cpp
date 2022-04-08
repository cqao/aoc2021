#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Need filename" << std::endl;
        exit(1);
    }
    
    std::string filename = argv[1];
    std::string line, sub;
    
    int val = 0;
    int hpos = 0;
    int vpos = 0;
    int aim = 0;
    int temp = 0;

    std::fstream fileStream(filename, fileStream.in);
    if (!fileStream.is_open())
    {
        std::cout << "Failed to open " << filename << "." << std::endl;
        exit(1);
    }

    while (fileStream)
    {
        std::getline (fileStream, line);

        char &b = line.back();
        val = atoi(&b);

        sub = line.substr(0, line.size()-2);
        std::cout << sub << std::endl;

        if (sub == "forward")
        {
            hpos+=val;
            temp = aim * val;
            vpos+=temp;
        }

        else if (sub == "up")
        {
            aim-=val;
        }

        else if (sub == "down")
        {
            aim+=val;
        }

        else
        {
            std::cout << "Not forward, up or down" << std::endl;    
        }
    }

    std::cout << "Final Answer: " << hpos*vpos << std::endl;



    return 0;
}