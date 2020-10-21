cc tcps3.c -o s -w 
cc tcpc3.c -o c -w 


# sudo fuser -k 5000/tcp

fuser -k 5000/tcp

printf "Server IP address :"

ifconfig

printf "Files Compiled \n to run server type  : ./s \n"


# ./s 
# ./c



note()
{

solution to address - port bind error / address already in use : 

To kill tcp port 7000


sudo apt-get install dsniff


sudo fuser -k 7000/tcp


}
