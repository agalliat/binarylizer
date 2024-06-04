#!/bin/sh

#mkdir -p ./images/dist
#npx ../_tools/npm-icon-gen -i ./images -o ./images/dist -r --ico --ico-name binarylizer --ico-sizes 16,32,48,64,128,256,512,1024 --icns --icns-name binarylizer --icns-sizes 16,32,48,64,128,256,512,1024 --favicon --favicon-name=favicon- --favicon-png-sizes 16,32,48,64,128,256,512,1024 --favicon-ico-sizes 16,32,48,64,128,256,512,1024

# ICO (Windows)
mkdir -p ./src/assets/icons
npx ../_tools/npm-icon-gen -i ./images -o ./src/assets/icons -r --ico --ico-name icon --ico-sizes 16,32,48,64,128,256,512,1024

# ICNS (MacOS)
mkdir -p ./src/assets/icons
npx ../_tools/npm-icon-gen -i ./images -o ./src/assets/icons -r --icns --icns-name icon --icns-sizes 16,32,48,64,128,256,512,1024
npx ../_tools/npm-icon-gen -i ./images -o ./packaging/dmg -r --icns --icns-name volume --icns-sizes 16,32,48,64,128,256,512,1024

# FAVICON (Web)
mkdir -p ./images/dist
npx ../_tools/npm-icon-gen -i ./images -o ./images/dist -r --favicon --favicon-name=favicon- --favicon-png-sizes 16,32,48,64,128,256,512,1024 --favicon-ico-sizes 16,32,48,64,128,256,512,1024
