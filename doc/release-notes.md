🗺️Tpc Core 👛 3.0.2 CE ©️ - 👒 RELEASE 👒  is now available from:
===============================

Is now available from:

  - CE release

    <https://github.com/cevap/tpc/releases

  - Tpc-coin release

    <https://github.com/tpc-coin/tpc/releases

This is a new minor-revision version release, including various bug fixes and
performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github:

  <https://github.com/cevap/tpc/issues>

Recommended Update
==============

🗺️Tpc Core 👛 3.0.2 CE ©️ - 👒 RELEASE 👒 is a recommended, semi-mandatory update for all users. This release contains transaction creation bug fixes for xTPC spends, automint calculation adjustments, and other various updates/fixes.

xTPC spending requires this update.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/Tpc-Qt (on Mac) or tpcd/tpc-qt (on Linux).

Compatibility
==============

🗺️Tpc Core 👛 is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support),
No attempt is made to prevent installing or running the software on Windows XP, you
can still do so at your own risk but be aware that there are known instabilities and issues.
Please do not report issues about Windows XP to the issue tracker.

🗺️Tpc Core 👛 should also work on most other Unix-like systems but is not
frequently tested on them.

### :exclamation::exclamation::exclamation: MacOS 10.13 High Sierra :exclamation::exclamation::exclamation:

**Currently there are issues with the 3.0.x gitian releases on MacOS version 10.13 (High Sierra), no reports of issues on older versions of MacOS.**


Notable Changes
===============

xTPC (_zerocoin for tpc_)
-------------------------
We have now zerocoin into tpc. More info about what it is and how to use it will follow in announcements and further release infos.

Snap/Snapcraft builds
----------------------------
Snapcraft is enabled and it can be simply installed by

`sudo snap install --edge tpc`

([Don’t have snapd installed?](https://docs.snapcraft.io/core/install))

Supported architectures: `i386, armhf, amd64`

Snap supported OS and installation instructions:

  - [Arch Linux](https://docs.snapcraft.io/core/install-arch-linux)
  - [Debian](https://docs.snapcraft.io/core/install-debian)
  - [Fedora](https://docs.snapcraft.io/core/install-fedora)
  - [Gentoo](https://docs.snapcraft.io/core/install-gentoo)
  - [Linux Mint](https://docs.snapcraft.io/core/install-linux-mint)
  - [Manjaro](https://docs.snapcraft.io/core/install-manjaro)
  - [OpenEmbedded/Yocto](https://docs.snapcraft.io/core/install-oe-yocto)
  - [openSUSE](https://docs.snapcraft.io/core/install-opensuse)
  - [OpenWrt](https://docs.snapcraft.io/core/install-openwrt)
  - [Solus](https://docs.snapcraft.io/core/install-solus)
  - [Ubuntu](https://docs.snapcraft.io/core/install-ubuntu)


Functions renamed
-----------------
Stashedsend is now Swift-X

New algorithm
-------------
We dropped MIDAS and will use DGW. More info will follow.

Automint
--------
Autominiting with zerocoin. More info will follow.

New look and design
-------------------
We have new look and desing, currently it is a dirty version. It includes new GUI layout, new colors.

Performance
-----------
Current source base is much faster and cleaner than tpc's previous one. It uses all cpu's and there are 
no performance issues which we could observe, it is just much faster then previous source base.

BIP38
-----
We have BIP38 including a tool with password encryption and decrpytion features

Blockexplorer
-------------
We finaly have built in blockexplorer which works on all tpc's networks.

User friendly
-------------
There are some new features which improve usability as well as user experience in general. More info to follow.

Auto Wallet Backup
---------------------
In addition to the automatic wallet backup that is done at each start of the client, a new automatic backup function has been added that will, by default, create a backup of the wallet file during each xTPC mint operation (xTPC spends which re-mint their change are also included in this). This functionality is controlled by the `-backupxion` command-line option, which defaults to `1` (enabled, auto-backup).

Users that wish to prevent this behavior (not recommended) can pass `-backupxion=0` at the command-line when starting the client, or add `backupxion=0` to their `Travelpaycoin.conf` file.

xTPC Automint Calculations
---------------------
A bug in the automint calculations was made apparent on mainnet when block times exceeded expectations, resulting in xTPC mint transactions that were in an unconfirmed state to still be treated as if they had never been minted. This caused automint to effectively mint more than what was intended.

xTPC Spending Fix
---------------------
The size of xTPC spend transactions is knowingly larger than normal transactions, and while this was expected, a much stricter check against the scriptsig size is used for mainnet, causing the transactions to be rejected by the mempool, and thus not being packaged into any blocks.

xTPC Transaction Recovery
---------------------
Due to the aforementioned issue with xTPC spending, users may find that their attempted spends are now conflicted and xTPC balances are not represented as expected. "Recovery" of these transactions can be done using the following methods:

1. GUI:

   The Privacy tab has the `Reset` and `Rescan` buttons that can be used to restore these mints/spends from a state of being marked as unavailable.

2. RPC:

   The RPC commands `resetspentzerocoin` and `resetmintzerocoin` are the command-line counterparts to the above, and can be used by users that do not use the GUI wallet.

RPC Changes
---------------------
The `bip38decrypt` command has had it's parameter order changed to be more consistent with it's counterpart. The command now expects the Tpc address as it's first parameter and the passphrase as it's second parameter.

Bip38 Compatibility With 3rd Party Tools
---------------------
The in-wallet bip38 encryption method was leaving the final 4 bytes of the encrypted key blank. This caused an incompatibility issue with 3rd party tools like the paper wallet generators that could decrypt bip38 encrypted keys. Cross-tool compatibility has now been restored.

3.0.2 Change log
=================

This release is a fork to the old chain. Detailed release notes follow.
We dropped MIDAS and use DGW as well as some other changes. Previous old version
was based on old projects which were not updated. One of our main goals for v3 release
was to get closer to bitcoin's source and update in general sources to some newer
and cleaner codebase then it was previously. We forked from PIVX which is better
maintenanced then previous releases of 🗺️Tpc Core 👛 which are based on obsolete code.
In this version everything is new, one big feature iz xTPC which iz zerocoin for
tpc. Port and other settings remain same. Please foolow our wiki for more information
about how to backup your wallet/keys and upgrade to new wallet as well as recovery paths
and detailed explanations of how to use new code. One big difference is finally restricting
in better was single mode masternode, as multi mode is not usefull within larger networks.

Additional files and features
=============================

bootstrap.dat
-----------------
Copy `bootstrap.dat` to your data dir and launch your client. After it finishes, `bootstrap.dat` will be automaticly renamed to `bootstrap.dat.old`

bootstrap.dat info
```
Hash of 550142: 4a9e4ee53bc441e0aadf788b5daa9b8d01a3a6debed01b5c599d6f7e22f4f7d0
Date of 550142: 2018-03-24 17:23:37
tx of 550142: 1464746
log2_work of 550142: 71.105709
```

Notable changes of source for the fork
======================================
### Fork
- #??? `???????` [Wallet] Implement old wallets sporks
- #??? `???????` [Wallet] Implement old wallets algorithm (MIDAS)

### RPC and other APIs
- #275 `059aaa9` [RPC] Change Parameter Order of bip38decrypt (presstab)

### P2P Protocol and Network Code
- #286 `85c0f53` [Main] Change sporkDB from smart ptr to ptr. (presstab)
- #292 `feadab4` Additional checks for double spending of zPiv serials. (presstab)

### Wallet
- #271 `5e9a086` [Wallet] Remove unused member wallet in UnlockContext inner class (Jon Spock)
- #279 `e734010` Add -backupzpiv startup flag. (presstab)
- #280 `fdc182d` [Wallet] Fix zPiv spending errors. (presstab)
- #282 `310f216` [Wallet] Count pending zPiv balance for automint. (presstab)
- #290 `004d7b6` Include both pending and mature zerocoins for automint calculations (presstab)

### GUI
- #268 `bc63f24` [GUI/RPC] Changed bubblehelp text + RPC startmasternode help text fixed (Mrs-X)
- #269 `5466a9b` Check if model is valid before using in transactionView (Jon Spock)
- #270 `bd2328e` [Qt] Make lock icon clickable to toggle wallet lock state (Fuzzbawls)
- #273 `f31136e` [Qt] Fix UI tab order and shortcuts (Mrs-X)
- #287 `74a1c3c` [Qt] Don't allow the Esc key to close the privacy tab (Fuzzbawls)
- #291 `cb314e6` [Qt] zPiv control quantity/amount fixes (rejectedpromise)

### Miscellaneous
- #266 `2d97b54` [Scripts] Fix location for aarch64 outputs in gitian-build.sh (Fuzzbawls)
- #272 `958f51e` [Minting] Replace deprecated auto_ptr. (presstab)
- #276 `03f14ba` Append BIP38 encrypted key with an 4 byte Base58 Checksum (presstab)
- #288 `2522aa1` Bad CBlockHeader copy. (furszy)

Credits
=======

Thanks to everyone who directly contributed to this release:
- Formax
- CEVAP

And to source contributors which provided base for this release with their project:
- Fuzzbawls
- Jon Spock
- Mrs-X
- furszy
- presstab
- rejectedpromise
- Warrows

As well as everyone that helped translating on [Transifex](https://www.transifex.com/projects/p/tpc/).

Setting up the Gitian image
======================

Credentials
--------------
user: `gitianuser`
pass: `cevap`

user: `root`
pass: `cevap`

On your machine edit or create `~/.ssh/config` and add:

```
Host gitian
    HostName localhost
    Port 22222
    User gitianuser
```

Open a new terminal tab and enter (_check your .ssh folder for file name, id_rsa.pub and id_ecdsa.pub are defaults_):

```
scp ~/.ssh/id_rsa.pub gitian:.ssh/authorized_keys
```

Now connect to your gitian with: `ssh gitian`, no password will be required for ssh connection.

Now build base vm:

```
cd gitian-builder
bin/make-base-vm --lxc --arch amd64 --suite trusty
```
There will be a lot of warnings printed during the build of the image. These can be ignored.

**Note**: When sudo asks for a password, enter the password for the user gitianuser not for root.

Getting and building the inputs
--------------------------------------
At this point you have two options, you can either use the automated script (found in https://github.com/cevap/tpc/blob/master/contrib/gitian-build.sh, only works in Debian/Ubuntu) or you could manually do everything by following this guide. If you are using the automated script, then run it with the --setup command. Afterwards, run it with the --build command (example: contrib/gitian-build.sh -b signer 3.0.2). Otherwise ignore this.

Follow the instructions in https://github.com/cevap/tpc/blob/master/doc/release-process.md in the bitcoin repository under 'Fetch and create inputs' to install sources which require manual intervention. Also optionally follow the next step: 'Seed the Gitian sources cache and offline git repositories' which will fetch the remaining files required for building offline.

_**Note**: please use our links here, I left cevap as I do not want to remove it later_

That's it, follow release notes and how to build on our repo

Build with gitian
============

Signer is key, please use your github public key _(or [create new gpg key](https://help.github.com/articles/generating-a-new-gpg-key/) for gitian only and [add it to your account](https://help.github.com/articles/adding-a-new-gpg-key-to-your-github-account/), the same goes for SSH key ([create](https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/) | [add](https://help.github.com/articles/adding-a-new-ssh-key-to-your-github-account/)_). To show your key, run in terminal: `gpg --list-secret-keys --keyid-format LONG`

The output will show you key/keys, like this:
```
tor@tor ~ $ gpg --list-secret-keys --keyid-format LONG
/home/tor/.gnupg/secring.gpg
----------------------------
sec   3072R/49464B32BA6683BA 2017-03-13
uid                          developer (dev@i2pmail.org) <dev@i2pmail.org>
ssb   3072R/78E10152BEC6C3C6 2017-03-13
```


Take the key from sec line,

  sec   3072R/**49464B32BA6683BA** 2017-03-13

which would be in this case `49464B32BA6683BA`. This is your SIGNER.

GPG does not have enough entropy
----------------------------------------------
If you use high encryption and set your key to 4096bits, you might get some message similar to this `GPG does not have enough entropy`.

One of workarounds would be package for generating entropy called haveged. Install `haveged` and `rng-tools` by running:
`sudo apt-get install -y haveged rng-tools`

then create entropy with:
```
# run it with sudo if it requires root access
cat /dev/random | rngtest -c 1000
``` 

Now you can create your key with `gpg --gen-key`

Gist gitian build scripts
----------------------------
**Note**: Please change SIGNER to your key and version to desired version, in current release it is version 3.0.2, in future releases gist will be updated.

If you use scripts, after wget has downloaded the script, run `sed -i 's/49464B32BA6683BA/YOURGPGKEY/g''  and replace `YOURGPGKEY` with your LONG Key ID. The same can be done with version.
 - Linux only: [build offline](https://gist.github.com/cevap/9d7ef39be185cc07c3d0a9b33da2fba5)
 - Windows only: [build offline](https://gist.github.com/cevap/5d6ac38f6e8530d45ab31499bc3a62ff)
 - MacOS only (without HighSierra)[build offline](https://gist.github.com/cevap/a5a90607da3a9b058b8c0aea20fdd75a)

Setup **signer** and **version**/branch
-------------------------------------------------

```
cd ./tpc
export SIGNER="49464B32BA6683BA" # Replace with your Key
export VERSION=3.0.2 # github branch
git fetch
git checkout v${VERSION}
cd ..

# update signature
cd ./gitian.sigs
git pull
cd ..

# update gitian builder
cd ./gitian-builder
git pull
cd ..

# Fetch and create inputs: (first time, or when dependency versions change)
cd ./gitian-builder
mkdir -p inputs
wget -P inputs https://github.com/cevap/osslsigncode/releases/download/v1.7.1/osslsigncode-Backports-to-1.7.1.patch
wget -P inputs -O inputs/v1.7.1.tar.gz https://github.com/cevap/osslsigncode/archive/v1.7.1.tar.gz
wget -P inputs https://github.com/cevap/MacOSX-SDKs/releases/download/MacOSX10.11.sdk-trusty/MacOSX10.11.sdk.tar.gz
cd ..

# prebuild tpc dependencies
cd ./gitian-builder
make -C ../tpc/depends download SOURCES_PATH=`pwd`/cache/common
cd ..
```

Building offline
------------------

```
cd ./gitian-builder

# Build offline for linux
./bin/gbuild --url tpc=/home/gitianuser/tpc,signature=/home/gitianuser/gitian.sigs --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-linux.yml

# Sign for linux
./bin/gsign --signer "$SIGNER" --release ${VERSION}-linux --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-linux.yml
mv build/out/tpc-*.tar.gz build/out/src/tpc-*.tar.gz ../

# Build offline for windows
./bin/gbuild --url tpc=/home/gitianuser/tpc,signature=/home/gitianuser/gitian.sigs --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-win.yml

# Sign for windows
./bin/gsign --signer "$SIGNER" --release ${VERSION}-win-unsigned --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-win.yml
mv build/out/tpc-*-win-unsigned.tar.gz inputs/tpc-win-unsigned.tar.gz
mv build/out/tpc-*.zip build/out/tpc-*.exe ../

# Build offline for mac os
./bin/gbuild --url tpc=/home/gitianuser/tpc,signature=/home/gitianuser/gitian.sigs --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-osx.yml

# Sign for macos
./bin/gsign --signer "$SIGNER" --release ${VERSION}-osx-unsigned --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-osx.yml
mv build/out/tpc-*-osx-unsigned.tar.gz inputs/tpc-osx-unsigned.tar.gz
mv build/out/tpc-*.tar.gz build/out/tpc-*.dmg ../
cd ..
```


Building online
---------------

```
# Build online for linux
./bin/gbuild --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-linux.yml

# Sign for linux
./bin/gsign --signer "$SIGNER" --release ${VERSION}-linux --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-linux.yml
mv build/out/tpc-*.tar.gz build/out/src/tpc-*.tar.gz ../

# Build online for windows
./bin/gbuild --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-win.yml

# Sign for windows
./bin/gsign --signer "$SIGNER" --release ${VERSION}-win-unsigned --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-win.yml
mv build/out/tpc-*-win-unsigned.tar.gz inputs/tpc-win-unsigned.tar.gz
mv build/out/tpc-*.zip build/out/tpc-*.exe ../

# Build online for mac os
./bin/gbuild --num-make 2 --memory 3000 --commit tpc=v${VERSION} ../tpc/contrib/gitian-descriptors/gitian-osx.yml

# Sign for macos
./bin/gsign --signer "$SIGNER" --release ${VERSION}-osx-unsigned --destination ../gitian.sigs/ ../tpc/contrib/gitian-descriptors/gitian-osx.yml
mv build/out/tpc-*-osx-unsigned.tar.gz inputs/tpc-osx-unsigned.tar.gz
mv build/out/tpc-*.tar.gz build/out/tpc-*.dmg ../
cd ..
```

Build reports
=============
#### Linux
```
81c6c81ea4cf67f11d40b6215fdf3b7914577368b238eb4da2f7ff887f3d7b3b  tpc-3.0.2-arm-linux-gnueabihf-debug.tar.gz
f3bf55bc9282a882410dabe793772501e85124322f8f30a1b0ae4f4684be0837  tpc-3.0.2-arm-linux-gnueabihf.tar.gz
3b780fd5ba985847251a93a97c3aedad282e8cecb641c8873aa1591e3d84b420  tpc-3.0.2-i686-pc-linux-gnu-debug.tar.gz
9483e8af1af7175efaf92c3efc99ec6ddee868e629be5269a9985abdbeade91c  tpc-3.0.2-i686-pc-linux-gnu.tar.gz
a57d962fd75f97a4b73d9fb65f43611acf15c7d9139e840d455c421bf7253170  tpc-3.0.2-x86_64-linux-gnu-debug.tar.gz
13ea2506bdf620d77d8316672adab68a0a5107ae9b1590a6ed5486f3b0509f63  tpc-3.0.2-x86_64-linux-gnu.tar.gz
30e0390dc5d5f3bfbd91f340884ab75ca30056ff49c5831edc49fcae8c9413af  src/tpc-3.0.2.tar.gz
76fa4b28ae291521be3ee12d22fa7d9b6085cafa0cc14c1c60b6b69f498d5a57  tpc-linux-3.1-res.yml
```
#### windows
```
Generating report
e7e3a92a32a8dc924e64d19a276af11cfe74193cc5aad26bc7335e2e2e835a57  tpc-3.0.2-win-unsigned.tar.gz
2a9b1199f03068c6ea18e5e25cd6736c15c7ddf9247ede67079bcd544c1426ad  tpc-3.0.2-win32-debug.zip
624c4d36d9145efcaac2a9ed00368f2aac61631a9b75ebfc546926009e395db0  tpc-3.0.2-win32-setup-unsigned.exe
49659943ab915444ab926bd392a34d9fb3397cf997f34e3deaa31f43bab185a7  tpc-3.0.2-win32.zip
1a2ba3aac86fb44355b7b879f6c269d5556b1e302f3a54602c51101eedc3efe6  tpc-3.0.2-win64-debug.zip
073f490607616680a5a5def73a1231885860aa047e526e7bf4694a4b88b11a56  tpc-3.0.2-win64-setup-unsigned.exe
6f88c1bb4eec9b077c2e1ee60e9371b184d460a920e6170610f67dbc786e9faf  tpc-3.0.2-win64.zip
679ac050e5555e097785b835f666de3d2e6b0e8af0dcefc7430ef3bfec386180  src/tpc-3.0.2.tar.gz
eec21196d7d4abab4fb8c32882fed5157271161ecba4693a67d6ca407503e030  tpc-win-3.1-res.yml
```
#### macos
```
7bc9149778661d03f5b26a97ff7dbbf8c9113d5198fe433e4e9b69cbb02f80f4  tpc-3.0.2-osx-unsigned.dmg
2ae951d05b053790e0916db1e519fbf3f37258741ae67ffa15a8ddf455881b9b  tpc-3.0.2-osx-unsigned.tar.gz
1b2f4dbcc02c423924a2dbbf2b813eca094fd796e1424a7478a14651d82524ae  tpc-3.0.2-osx64.tar.gz
679ac050e5555e097785b835f666de3d2e6b0e8af0dcefc7430ef3bfec386180  src/tpc-3.0.2.tar.gz
0be4184f68aaf67653b704e0bed30a83ede84fcea9c53ca39aa50c804acff614  tpc-osx-3.1-res.yml
```