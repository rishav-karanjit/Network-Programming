cc mcast_c.c -o c -w
cc mcast_s.c -o s -w


# sudo fuser -k 4321/udp

fuser -k 4321/udp

# ./c &
# ./c &
# ./c &
# ./s
