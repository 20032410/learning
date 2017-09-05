#!/bin/bash
#ifconfig br-lan 192.168.1.140
#route add -net 0.0.0.0/0 gateway 192.168.1.1
#echo "nameserver 223.5.5.5" >> /etc/resolv.conf
iw dev wlan1 interface add mesh_iface type mp
iw dev mesh_iface set channel 1
iw dev mesh_iface set meshid mymesh
ifconfig mesh_iface 192.168.2.130
