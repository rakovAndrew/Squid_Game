#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream>
//#include "first_laboratory_work/choose_path.h"

using namespace std;
using namespace std_msgs;
using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "publisher");
    NodeHandle handler;
    //ServiceClient publisher = handler.serviceClient<first_laboratory_work::choose_path>("path_to_win");
    //first_laboratory_work::choose_path srv;
    char path;
    while(ok())
    {
        cout << "Choose path to win. You have to write \"l\" to take left side or \"r\" to take right side:";
        cin >> path;
        /*srv.request.turn = path;
        if(publisher.call(srv))
        {
            cout << srv.response.status << endl;
        }
        else
        {
            cout << "Connection problems" << endl;
            return -1;
        }*/
    }

    return 0;
}

