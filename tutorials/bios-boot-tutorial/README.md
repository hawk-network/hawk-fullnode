# Bios Boot Tutorial

The `bios-boot-tutorial.py` script simulates the HAWK-NETWORK bios boot sequence.

``Prerequisites``:

1. Python 3.x
2. CMake
3. git

``Steps``:

1. Install hawknwk binaries by following the steps outlined in below tutorial
[Install hawknwk binaries](https://github.com/HAWK-NETWORK/eos#mac-os-x-brew-install)

2. Install hawknwk.cdt binaries by following the steps outlined in below tutorial
[Install hawknwk.cdt binaries](https://github.com/HAWK-NETWORK/hawknwk.cdt#binary-releases)

3. Compile hawknwk.contracts

```bash
$ cd ~
$ git clone https://github.com/HAWK-NETWORK/hawknwk.contracts.git
$ cd ./hawknwk.contracts/
$ ./build.sh
$ pwd

```

4. Make note of the directory where the contracts were compiled
The last command in the previous step printed on the bash console the contracts' directory, make note of it, we'll reference it from now on as `HAWK-NETWORK_CONTRACTS_DIRECTORY`

5. Launch the `bios-boot-tutorial.py` script
Minimal command line to launch the script below, make sure you replace `HAWK-NETWORK_CONTRACTS_DIRECTORY` with actual directory

```bash
$ cd ~
$ git clone https://github.com/HAWK-NETWORK/eos.git
$ cd ./eos/tutorials/bios-boot-tutorial/
$ python3 bios-boot-tutorial.py --cleos="cleos --wallet-url http://127.0.0.1:6666 " --nodeos=nodeos --keosd=keosd --contracts-dir="/HAWK-NETWORK_CONTRACTS_DIRECTORY/" -a

```

See [HAWK-NETWORK Documentation Wiki: Tutorial - Bios Boot](https://github.com/HAWK-NETWORK/eos/wiki/Tutorial-Bios-Boot-Sequence) for additional information.