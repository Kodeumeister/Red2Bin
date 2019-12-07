#
#	Name: Red2Bin Makefile
#	Author: William Kimberley (Kodeumeister)
#	Date Modified: 2019-12-07
#	Date Created: 2019-12-07
#

release:
	g++ -Wall -std=c++11 red2bin.cpp -o red2bin.exe
	strip -S red2bin.exe

debug:
	g++ -Wall --std=c++11 -DDEBUG red2bin.cpp -o red2bin.exe