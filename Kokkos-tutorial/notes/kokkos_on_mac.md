## Install Kokkos on Mac OS X

1. First install CXX compiler (clang associated with the Xcode is not recommended)
	1. Install brew or port to enable package installing on Mac OS X
		1. Install Brew
		``` bash
		/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

		```
		1. Brew installs packages you need
		``` bash
		brew install wget

		```
		1. Homebrew installs packages to their own directory and then symlinks their files into /usr/local (on macOS Intel).
		``` bash
		cd /usr/local
		find Cellar

		ls -l bin
		```
	1. Install GNU compiler
		``` bash
		brew install gcc
		```