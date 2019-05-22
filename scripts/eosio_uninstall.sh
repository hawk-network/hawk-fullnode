#! /bin/bash

OPT_LOCATION=$HOME/opt

binaries=(
   cleos
   hawknwk-abigen
   hawknwk-launcher
   hawknwk-s2wasm
   hawknwk-wast2wasm
   hawknwkcpp
   keosd
   nodeos
   hawknwk-applesdemo
)

if [ -d $OPT_LOCATION/hawknwk ]; then
   printf "Do you wish to remove this install? (requires sudo)\n"
   select yn in "Yes" "No"; do
      case $yn in
         [Yy]* )
            if [ "$(id -u)" -ne 0 ]; then
               printf "\nThis requires sudo, please run ./hawknwk_uninstall.sh with sudo\n\n"
               exit -1
            fi

            pushd $HOME &> /dev/null
            pushd opt &> /dev/null
            rm -rf hawknwk
            # Handle cleanup of directories created from installation
            if [ "$1" == "--full" ]; then
               if [ -d ~/Library/Application\ Support/hawknwk ]; then rm -rf ~/Library/Application\ Support/hawknwk; fi # Mac OS
               if [ -d ~/.local/share/hawknwk ]; then rm -rf ~/.local/share/hawknwk; fi # Linux
            fi
            popd &> /dev/null
            pushd bin &> /dev/null
            for binary in ${binaries[@]}; do
               rm ${binary}
            done
            popd &> /dev/null
            pushd lib/cmake &> /dev/null
            rm -rf hawknwk
            popd &> /dev/null

            break;;
         [Nn]* )
            printf "Aborting uninstall\n\n"
            exit -1;;
      esac
   done
fi

if [ -d "/usr/local/hawknwk" ]; then
   printf "Do you wish to remove this install? (requires sudo)\n"
   select yn in "Yes" "No"; do
      case $yn in
         [Yy]* )
            if [ "$(id -u)" -ne 0 ]; then
               printf "\nThis requires sudo, please run ./hawknwk_uninstall.sh with sudo\n\n"
               exit -1
            fi

            pushd /usr/local &> /dev/null
            pushd opt &> /dev/null
            rm -rf hawknwk
            # Handle cleanup of directories created from installation
            if [ "$1" == "--full" ]; then
               if [ -d ~/Library/Application\ Support/hawknwk ]; then rm -rf ~/Library/Application\ Support/hawknwk; fi # Mac OS
               if [ -d ~/.local/share/hawknwk ]; then rm -rf ~/.local/share/hawknwk; fi # Linux
            fi
            popd &> /dev/null
            pushd bin &> /dev/null
            for binary in ${binaries[@]}; do
               rm ${binary}
            done
            popd &> /dev/null
            pushd lib/cmake &> /dev/null
            rm -rf hawknwk
            popd &> /dev/null

            break;;
         [Nn]* )
            printf "Aborting uninstall\n\n"
            exit -1;;
      esac
   done
fi
