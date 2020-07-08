void ms_error(int number, std::string description, bool pause = 0)
{
    std::cout<<"ERROR: "<<number<<"\n";
    std::cout<<description<<"\n";
    if(pause)
    {
        system("PAUSE");
    }
}
