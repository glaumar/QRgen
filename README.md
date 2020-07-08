# QRgen
A simple QRCode generator based on Qt and QZXing     

## Dependency
[QZXing](https://github.com/ftylitak/qzxing)

## How to install QZXing in Linux

Clone the qzxing repository

```
$ git clone git@github.com:ftylitak/qzxing.git
$ cd qzxing
```

Open `src/QZXing.pro` and uncomment `#qzxing_qml` like this

```
CONFIG += \
          enable_decoder_1d_barcodes \
          enable_decoder_qr_code \
          enable_decoder_data_matrix \
          enable_decoder_aztec \
          enable_decoder_pdf17 \
          enable_encoder_qr_code \
          qzxing_qml 
          # qzxing_multimedia
          # staticlib
```

Build and install

```
$ qmake src/QZXing.pro
$ make
$ sudo make install
```

## Screenshot

![](https://raw.githubusercontent.com/glaumar/QRgen/master/Screenshot.png)









