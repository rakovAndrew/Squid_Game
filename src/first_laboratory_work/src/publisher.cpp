#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream>
#include "../../../devel/include/first_laboratory_work/ChoosePath.h"

using namespace std;
using namespace std_msgs;
using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "publisher");
    NodeHandle handler;
    ServiceClient publisher = handler.serviceClient<first_laboratory_work::ChoosePath>("path_to_win");
    first_laboratory_work::ChoosePath srv;
    string path;
    while(ok())
    {
        cout << "Choose path to win. You have to write \"l\" to take left side or \"r\" to take right side:";
        cin >> path;
        srv.request.path = path;
        if(publisher.call(srv))
        {
            cout << srv.response.biPath << endl;
        }
        else
        {
            cout << "Connection problems" << endl;
            return -1;
        }
    }

    return 0;
}

