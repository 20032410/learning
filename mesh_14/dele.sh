#!/bin/bash
#renew eth0 ip address
#ifconfig eth0 192.168.3.1 netmask 255.255.255.0
route del -net 0.0.0.0/0 gateway 192.168.1.1
#route add -net 0.0.0.0/0 gateway 192.168.1.1
#echo "nameserver 223.5.5.5" >> /etc/resolv.conf

