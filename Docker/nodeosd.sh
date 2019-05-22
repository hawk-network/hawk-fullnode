#!/bin/sh
cd /opt/hawknwk/bin

if [ ! -d "/opt/hawknwk/bin/data-dir" ]; then
    mkdir /opt/hawknwk/bin/data-dir
fi

if [ -f '/opt/hawknwk/bin/data-dir/config.ini' ]; then
    echo
  else
    cp /config.ini /opt/hawknwk/bin/data-dir
fi

if [ -d '/opt/hawknwk/bin/data-dir/contracts' ]; then
    echo
  else
    cp -r /contracts /opt/hawknwk/bin/data-dir
fi

while :; do
    case $1 in
        --config-dir=?*)
            CONFIG_DIR=${1#*=}
            ;;
        *)
            break
    esac
    shift
done

if [ ! "$CONFIG_DIR" ]; then
    CONFIG_DIR="--config-dir=/opt/hawknwk/bin/data-dir"
else
    CONFIG_DIR=""
fi

exec /opt/hawknwk/bin/nodeos $CONFIG_DIR "$@"
