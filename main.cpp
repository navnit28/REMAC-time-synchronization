/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int convert_string_time_in_seconds(string tim)
{
    int hr=((tim[0]-'0')*10+tim[1]-'0');
    int mi=((tim[3]-'0')*10+tim[4]-'0');
    return hr*3600 + mi*60;
}
string convert_seconds_to_time_string(int time_in_seconds)
{
    // cout<<time_in_seconds<<endl;
    int hr=time_in_seconds/3600;
    int mi=(time_in_seconds%3600)/60;
    string mi_instring=to_string(mi);
    string tim=to_string(hr)+":";
    if(mi_instring.length()==1)
    {
        tim+='0';
        tim+=mi_instring;
    }
    else{
        tim+=mi_instring;
    }
    // cout<<tim;
    return tim;
}
void time_synchronization(string &reception_time,string &current_time,int max_delay_offset){
    int reception_time_in_seconds=convert_string_time_in_seconds(reception_time);
    int current_time_in_seconds=convert_string_time_in_seconds(current_time);
    // cout<<"reception_time_in_seconds "<<reception_time_in_seconds<<"\n";
    // cout<<"current_time_in_seconds "<<current_time_in_seconds<<"\n";
    int new_time_in_seconds;
    if(reception_time_in_seconds-current_time_in_seconds<max_delay_offset)
    {
        // cout<<"here ";
        new_time_in_seconds=reception_time_in_seconds+(max_delay_offset+reception_time_in_seconds-current_time_in_seconds)/2;
        // cout<<"new_time_in_seconds "<<new_time_in_seconds<<"\n";
    }
    else{
        new_time_in_seconds=reception_time_in_seconds+max_delay_offset;
        // cout<<"new time_in_seconds "<<new_time_in_seconds<<"\n";
    }
    current_time=convert_seconds_to_time_string(new_time_in_seconds);
    // cout<<"current_time "<<current_time;
}
int main()
{
    // cout<<"hi\n";
    string reception_time="00:04";
    string current_time="00:02";
    int max_delay_offset=120;
    cout<<"previous current_time "<<current_time<<"\n";
    cout<<"reception_time "<<reception_time<<"\n";
    time_synchronization(reception_time,current_time,max_delay_offset);
    cout<<"new current_time "<<current_time<<"\n";
    return 0;
}
