#############################################################################
# Makefile for building: countdowntimer
# Generated by qmake (2.01a) (Qt 4.5.3) on: Fri 15. Jan 14:21:01 2010
# Project:  countdowntimer.pro
# Template: subdirs
# Command: c:/MADDE/0.5/targets/fremantle-qt-0942/bin/qmake.exe -unix -o Makefile countdowntimer.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = c:/MADDE/0.5/targets/fremantle-qt-0942/bin/qmake.exe
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		sub-src

src/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) src/ || $(MKDIR) src/ 
	cd src/ && $(QMAKE) src.pro -unix -o $(MAKEFILE)
sub-src-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) src/ || $(MKDIR) src/ 
	cd src/ && $(QMAKE) src.pro -unix -o $(MAKEFILE)
sub-src: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE)
sub-src-make_default: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) 
sub-src-make_first: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) first
sub-src-all: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) all
sub-src-clean: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) clean
sub-src-distclean: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) distclean
sub-src-install_subtargets: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) install
sub-src-uninstall_subtargets: src/$(MAKEFILE) FORCE
	cd src/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: countdowntimer.pro  ../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/default/qmake.conf ../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/g++.conf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/unix.conf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/linux.conf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/qconfig.pri \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt_functions.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt_config.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/default_pre.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/debug.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/default_post.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/warn_on.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/unix/thread.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/moc.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/resources.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/uic.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/yacc.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/lex.prf \
		../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -unix -o Makefile countdowntimer.pro
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/g++.conf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/unix.conf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/common/linux.conf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/qconfig.pri:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt_functions.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt_config.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/default_pre.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/debug.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/default_post.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/warn_on.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/qt.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/unix/thread.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/moc.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/resources.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/uic.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/yacc.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/lex.prf:
../../../sysroots/fremantle-qt-arm-sysroot-0942/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -unix -o Makefile countdowntimer.pro

qmake_all: sub-src-qmake_all FORCE

make_default: sub-src-make_default FORCE
make_first: sub-src-make_first FORCE
all: sub-src-all FORCE
clean: sub-src-clean FORCE
distclean: sub-src-distclean FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-src-install_subtargets FORCE
uninstall_subtargets: sub-src-uninstall_subtargets FORCE

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:
