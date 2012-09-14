#!/bin/bash
plat=`uname`

if [ $plat == "Darwin" ]
then
  echo "Configuring for OS X"
  cp make_osx Makefile
else
  echo "Configuring for Linux"
  cp make_linux Makefile
fi
