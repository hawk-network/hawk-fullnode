FROM hawknwk/builder
ARG branch=master
ARG symbol=SYS

RUN git clone -b $branch https://github.com/HAWK-NETWORK/eos.git --recursive \
    && cd eos && echo "$branch:$(git rev-parse HEAD)" > /etc/hawknwk-version \
    && cmake -H. -B"/opt/hawknwk" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/opt/hawknwk -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /opt/hawknwk --target install \
    && cp /eos/Docker/config.ini / && ln -s /opt/hawknwk/contracts /contracts && cp /eos/Docker/nodeosd.sh /opt/hawknwk/bin/nodeosd.sh && ln -s /eos/tutorials /tutorials

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates vim psmisc python3-pip && rm -rf /var/lib/apt/lists/*
RUN pip3 install numpy
ENV HAWK-NETWORK_ROOT=/opt/hawknwk
RUN chmod +x /opt/hawknwk/bin/nodeosd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
ENV PATH /opt/hawknwk/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
