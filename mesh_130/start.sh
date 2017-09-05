#!/bin/bash
ifconfig br-lan 192.168.1.140
route add -net 0.0.0.0/0 gateway 192.168.1.1
echo "nameserver 223.5.5.5" >> /etc/resolv.conf

