#!/bin/bash
ifconfig eth0 33.16.85.14 netmask 255.255.255.0
#renew the eth0 for cpe
route add -net 0.0.0.0/0 gateway 33.16.85.10
#echo "nameserver 223.5.5.5" >> /etc/resolv.conf

