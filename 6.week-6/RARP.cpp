#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> IP{"223.2.1.160","223.2.1.161","223.2.1.162","223.2.1.163","223.2.1.164","223.2.1.165"};
	vector<string> MAC{"01:23:45:67:89:AA","01:23:45:67:89:AB","01:23:45:67:89:AC","01:23:45:67:89:AD","01:23:45:67:89:AE","01:23:45:67:89:AF"};
    cout<<"The available IP addresses and their corresponding MAC addresses are :\n";
    for(int i=0;i<IP.size();i++)
    {
        cout<<"IP address: "<<IP[i]<<" -------->  "<<"MAC address:  "<<MAC[i]<<endl;
    }
    cout<<"Enter the source IP address :\n";
    string ip1;
    getline(cin,ip1);
    cout<<"Enter the destination MAC address :\n";
    string mac2;
    getline(cin,mac2);
    string mac1="";
    string ip2="255.255.255.255";
    string ip2final="";
    for(int i=0;i<IP.size();i++)
    {
        if(IP[i]==ip1)
        {
            mac1=MAC[i];
        }
        if(MAC[i]==mac2)
        {
            ip2final=IP[i];
        }
    }
    if(ip2final=="")
    {
        cout<<"The IP address you entered doesnt match those in the network \n";
        cout<<"Program ended\n";
        return -1;
    }
    cout<<"The MAC address of the source is : "<<mac1<<endl;
    cout<<"For now the IP address of the source is : "<<ip2<<endl;
    cout<<"This msg with the details("<<ip1<<","<<ip2<<","<<mac1<<","<<mac2<<") is sent to all other devices in the network(broadcasted) as datagram\n";
    cout<<"Then we get a unicast msg from the destination device with all the above details but with crct IP address as "<<ip1<<","<<ip2final<<","<<mac1<<","<<mac2<<")\n";
    cout<<"So the IP address of the destination device is : "<<ip2final<<endl;
    return 1;
}