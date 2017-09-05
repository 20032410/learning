#!/bin/bash
#edit by lielieli 20170730
#for mesh client from wlan0 
#ifconfig br-lan 192.168.1.140
#route add -net 0.0.0.0/0 gateway 192.168.1.1
#echo "nameserver 223.5.5.5" >> /etc/resolv.conf
iptables -F
iptables -X
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
iptables -A FORWARD -i eth0 -o mesh0 -j ACCEPT
iptables -A FORWARD -i mesh0 -o eth0 -j ACCEPT
iptables -L -n
printf "done\n"
