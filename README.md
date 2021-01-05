# libKeyFinder

libKeyFinder is a small C++11 library for estimating the musical key of digital audio. It is published under the [GNU General Public License version 3 or later](LICENSE).

It was written by [Ibrahim Shaath](http://ibrahimshaath.co.uk/keyfinder/) who wrote it in 2011 as part of a master's thesis in computer science. A [GUI application](https://github.com/ibsh/is_KeyFinder) to use it is available for [macOS](http://www.ibrahimshaath.co.uk/keyfinder/bins/KeyFinder-OSX-2-4.zip) and [Windows](http://www.ibrahimshaath.co.uk/keyfinder/bins/KeyFinder-WIN-1-25.zip), however that is no longer maintained and does not build on contemporary Linux distributions.

In 2020, Ibrahim handed over maintenance of libKeyFinder to the [Mixxx DJ software](https://mixxx.org) team who incorporated it into Mixxx as of Mixxx 2.3. If you want to discuss anything related to libKeyFinder with us, please get in touch on the [Mixxx Zulip chat](https://mixxx.zulipchat.com/#narrow/stream/109171-development/topic/KeyFinder). Contributions are welcome by opening pull requests and issues on [GitHub](https://github.com/mixxxdj/libKeyFinder).

## Installation

First, you will need to install [FFTW3](http://www.fftw.org/download.html):

* Fedora: `$ sudo dnf install fftw-devel catch2-devel`
* Debian & Ubuntu: `$ sudo apt install libfftw3-dev`
* Arch Linux: `$ sudo pacman -S fftw catch2`
* macOS and homebrew: `$ brew install fftw catch2`

[catch2](https://github.com/catchorg/Catch2) is required for building the tests. It is not available in Debian 10 or Ubuntu 20.04 LTS,
although it is available in Ubuntu 20.10 and Debian 11 testing. If catch2 is not found, it will be automatically downloaded by CMake.
Alternatively, it's possible disable building the unit tests by passing `-DBUILD_TESTING=OFF` to CMake.

Once dependencies are installed, build `libKeyFinder`:

```sh
$ cmake -DCMAKE_INSTALL_PREFIX /where/you/want/to/install/to -S . -B build
$ cmake --build build --parallel number-of-cpu-cores
$ cmake --install build
```

If you want to build libKeyFinder statically, add `-DBUILD_SHARED_LIBS=OFF` to the first call to `cmake` above.

## Testing

The tests are built together with the library. Simply run ctest from the build directory:

```sh
$ cd build
$ ctest --parallel number-of-cpu-cores
```

Note that there is a known intermittent failure in the `FftAdapterTest/ForwardAndBackward` test. Try running the tests a handful of times to determine whether you are hitting the intermittent failure or have introduced a new bug.

## Usage

Refer to the [documentation](https://mixxxdj.github.io/libKeyFinder/).
