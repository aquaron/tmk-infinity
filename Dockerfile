FROM ubuntu

ENV _root /tmk_keyboard/keyboard/infinity 

RUN apt-get update \
 && apt-get upgrade -y \
 && apt-get install -y \
  git make \
  gcc-arm-none-eabi \
  gcc-arm-linux-gnueabi \
  libusb-1.0-0-dev \
 && rm -r /var/lib/apt/lists/* \
 && git clone https://github.com/tmk/tmk_keyboard.git

COPY bin $_root

WORKDIR $_root

ENTRYPOINT [ "./runme.sh" ]
