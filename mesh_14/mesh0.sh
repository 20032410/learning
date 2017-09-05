#!/bin/bash
#ifconfig br-lan 192.168.1.140
#route add -net 0.0.0.0/0 gateway 192.168.1.1
#echo "nameserver 223.5.5.5" >> /etc/resolv.conf
iw dev wlan1 del
iw phy phy1 interface add mesh0 type mesh
iw dev mesh0 set meshid mymesh
iw dev mesh0 set channel 1
ifconfig mesh0 hw ether 00:1C:11:11:11:12
ifconfig mesh0 up
ifconfig mesh0 192.168.2.140
#iw dev mesh0 station dump
