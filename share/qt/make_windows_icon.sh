#!/bin/bash
# create multiresolution windows icon
#mainnet
ICON_SRC=../../src/qt/res/icons/tpc.png
ICON_DST=../../src/qt/res/icons/tpc.ico
convert ${ICON_SRC} -resize 16x16 tpc-16.png
convert ${ICON_SRC} -resize 32x32 tpc-32.png
convert ${ICON_SRC} -resize 48x48 tpc-48.png
convert tpc-16.png tpc-32.png tpc-48.png ${ICON_DST}
#testnet
ICON_SRC=../../src/qt/res/icons/tpc_testnet.png
ICON_DST=../../src/qt/res/icons/tpc_testnet.ico
convert ${ICON_SRC} -resize 16x16 tpc-16.png
convert ${ICON_SRC} -resize 32x32 tpc-32.png
convert ${ICON_SRC} -resize 48x48 tpc-48.png
convert tpc-16.png tpc-32.png tpc-48.png ${ICON_DST}
rm tpc-16.png tpc-32.png tpc-48.png
#regtest
ICON_SRC=../../src/qt/res/icons/tpc_regtest.png
ICON_DST=../../src/qt/res/icons/tpc_regtest.ico
convert ${ICON_SRC} -resize 16x16 tpc-16.png
convert ${ICON_SRC} -resize 32x32 tpc-32.png
convert ${ICON_SRC} -resize 48x48 tpc-48.png
convert tpc-16.png tpc-32.png tpc-48.png ${ICON_DST}
rm tpc-16.png tpc-32.png tpc-48.png
#unittest
ICON_SRC=../../src/qt/res/icons/tpc_unittest.png
ICON_DST=../../src/qt/res/icons/tpc_unittest.ico
convert ${ICON_SRC} -resize 16x16 tpc-16.png
convert ${ICON_SRC} -resize 32x32 tpc-32.png
convert ${ICON_SRC} -resize 48x48 tpc-48.png
convert tpc-16.png tpc-32.png tpc-48.png ${ICON_DST}
rm tpc-16.png tpc-32.png tpc-48.png