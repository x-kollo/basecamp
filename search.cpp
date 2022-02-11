
#include "search.h"

//#define DEBUG

void search(const std::filesystem::path & home_path, const std::string & file)
{
    static bool find = false; 
    std::thread th;
    for(auto dir : std::filesystem::directory_iterator(home_path,std::filesystem::directory_options::skip_permission_denied))
    {
        if(!dir.exists())
            continue;
        if(find)
        {
            active_threads--;
#ifdef DEBUG
            std::cout << "[Thread-Out] ID: " << std::this_thread::get_id() << ". active_threads = " << active_threads << "\n";
#endif        
            return;
        }
#ifdef DEBUG
        std::cout << "[Info] Thread ID: " << std::this_thread::get_id() << "\t" << dir.path() << "\t" << "active_threads = " << active_threads << "\n";     
#endif
        if(dir.path().filename() == file)
        {
            find = true;
            std::ofstream outfile("result.txt");
            outfile << "Path: " << dir.path() << "\n";
            outfile.close();      
            return;
        }    
        if(dir.is_directory() && std::thread::hardware_concurrency() >= active_threads+1)
        {
            ++active_threads;
            th = std::thread(search,dir.path(),file);      
#ifdef DEBUG
            std::cout << "[Thread-In] ID: "  << th.get_id() << "\n"; 
#endif
            th.join();
        }      
    }
    active_threads--;
#ifdef DEBUG
    std::cout << "[Thread-Out] ID: " << std::this_thread::get_id() << ". active_threads = " << active_threads << "\n";
#endif
    return;
}