#############################################################################
# Makefile for building: CrucisIPC
# Generated by qmake (3.1) (Qt 6.4.1)
# Project:  CrucisIPC.pro
# Template: app
# Command: D:\QT\6.4.1\mingw_64\bin\qmake.exe -o Makefile CrucisIPC.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\QT\6.4.1\mingw_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\QT\6.4.1\mingw_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\QT\6.4.1\mingw_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
IDC           = idc
IDL           = midl
ZIP           = zip -r -9
DEF_FILE      = 
RES_FILE      = CrucisIPC_resource_res.o
SED           = $(QMAKE) -install sed
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: CrucisIPC.pro D:/QT/6.4.1/mingw_64/mkspecs/win32-g++/qmake.conf D:/QT/6.4.1/mingw_64/mkspecs/features/spec_pre.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/device_config.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/sanitize.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/gcc-base.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/g++-base.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/windows-vulkan.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/g++-win32.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/common/windows-desktop.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/qconfig.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_freetype.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_libpng.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3danimation.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3danimation_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dcore.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dextras.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dinput.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dlogic.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquick.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickanimation.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3drender.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3drender_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_activeqt.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_activeqt_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axbase_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axcontainer.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axcontainer_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axserver.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axserver_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bluetooth.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bodymovin_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_charts.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_charts_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_chartsqml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_chartsqml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_concurrent.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_core.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_core_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualization.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualization_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualizationqml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualizationqml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_dbus.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designer.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designer_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_gui.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_gui_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_help.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_help_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_httpserver.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_httpserver_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_jsonrpc_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssettings.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_languageserver_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_linguist.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimedia.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediaquick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_network.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_network_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_networkauth.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_networkauth_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_nfc.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_nfc_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_opengl.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_png_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioning.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioning_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioningquick.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioningquick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_printsupport.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmltest.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3d.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3d_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetimport.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetimport_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetutils.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetutils_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3deffects.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3deffects_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dglslparser_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dhelpers.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dhelpers_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3diblbaker.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3diblbaker_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticleeffects.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticleeffects_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticles.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticles_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysics.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysics_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysicshelpers.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysicshelpers_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3druntimerender.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3druntimerender_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dspatialaudio_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dutils.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dutils_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktimeline.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktimeline_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjects.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjectsqml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjectsqml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_repparser.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_repparser_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxmlqml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxmlqml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensors.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensors_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensorsquick.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensorsquick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialbus.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialport.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialport_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_shadertools.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_shadertools_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_spatialaudio.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_spatialaudio_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sql.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sql_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachine.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachine_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachineqml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachineqml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svg.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svg_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_testlib.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_texttospeech.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_texttospeech_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_tools_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uitools.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webchannel.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_websockets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_websockets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webview.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webview_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webviewquick.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webviewquick_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_widgets.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_xml.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_xml_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri \
		D:/QT/6.4.1/mingw_64/mkspecs/features/qt_functions.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/qt_config.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/win32-g++/qmake.conf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		D:/QT/6.4.1/mingw_64/mkspecs/features/exclusive_builds.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/toolchain.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/default_pre.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/win32/default_pre.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/resolve_config.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/exclusive_builds_post.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/default_post.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/qml_debug.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/entrypoint.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/precompile_header.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/warn_on.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/qt.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/resources_functions.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/resources.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/moc.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/win32/opengl.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/uic.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/qmake_use.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/file_copies.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/win32/windows.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/testcase_targets.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/exceptions.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/yacc.prf \
		D:/QT/6.4.1/mingw_64/mkspecs/features/lex.prf \
		CrucisIPC.pro \
		D:/QT/6.4.1/mingw_64/lib/Qt6Svg.prl \
		D:/QT/6.4.1/mingw_64/lib/Qt6Widgets.prl \
		D:/QT/6.4.1/mingw_64/lib/Qt6Gui.prl \
		D:/QT/6.4.1/mingw_64/lib/Qt6Core.prl \
		D:/QT/6.4.1/mingw_64/lib/Qt6EntryPoint.prl \
		D:/QT/6.4.1/mingw_64/mkspecs/features/build_pass.prf \
		icons.qrc
	$(QMAKE) -o Makefile CrucisIPC.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
D:/QT/6.4.1/mingw_64/mkspecs/features/spec_pre.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/device_config.prf:
D:/QT/6.4.1/mingw_64/mkspecs/common/sanitize.conf:
D:/QT/6.4.1/mingw_64/mkspecs/common/gcc-base.conf:
D:/QT/6.4.1/mingw_64/mkspecs/common/g++-base.conf:
D:/QT/6.4.1/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
D:/QT/6.4.1/mingw_64/mkspecs/common/windows-vulkan.conf:
D:/QT/6.4.1/mingw_64/mkspecs/common/g++-win32.conf:
D:/QT/6.4.1/mingw_64/mkspecs/common/windows-desktop.conf:
D:/QT/6.4.1/mingw_64/mkspecs/qconfig.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_freetype.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_ext_libpng.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3danimation.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3danimation_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dcore.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dcore_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dextras.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dextras_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dinput.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dinput_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dlogic.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquick.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickanimation.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickextras.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickextras_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickinput.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickinput_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickrender.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickrender_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickscene2d.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3drender.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_3drender_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_activeqt.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_activeqt_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axbase_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axcontainer.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axcontainer_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axserver.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_axserver_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bluetooth.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_bodymovin_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_charts.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_charts_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_chartsqml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_chartsqml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_concurrent.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_core.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_core_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualization.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualization_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualizationqml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_datavisualizationqml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_dbus.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designer.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designer_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_gui.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_gui_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_help.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_help_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_httpserver.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_httpserver_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_jsonrpc_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssettings.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_languageserver_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_linguist.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimedia.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimedia_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediaquick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_network.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_network_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_networkauth.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_networkauth_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_nfc.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_nfc_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_opengl.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_png_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioning.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioning_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioningquick.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_positioningquick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_printsupport.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmltest.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3d.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3d_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetimport.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetimport_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetutils.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dassetutils_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3deffects.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3deffects_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dglslparser_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dhelpers.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dhelpers_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3diblbaker.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3diblbaker_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticleeffects.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticleeffects_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticles.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dparticles_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysics.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysics_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysicshelpers.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dphysicshelpers_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3druntimerender.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3druntimerender_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dspatialaudio_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dutils.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick3dutils_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktimeline.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quicktimeline_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjects.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjects_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjectsqml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_remoteobjectsqml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_repparser.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_repparser_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxmlqml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_scxmlqml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensors.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensors_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensorsquick.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sensorsquick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialbus.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialbus_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialport.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_serialport_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_shadertools.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_shadertools_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_spatialaudio.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_spatialaudio_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sql.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_sql_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachine.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachine_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachineqml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_statemachineqml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svg.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svg_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_testlib.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_texttospeech.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_texttospeech_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_tools_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uitools.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_virtualkeyboard.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webchannel.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webchannel_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_websockets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_websockets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webview.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webview_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webviewquick.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_webviewquick_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_widgets.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_xml.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_xml_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri:
D:/QT/6.4.1/mingw_64/mkspecs/features/qt_functions.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/qt_config.prf:
D:/QT/6.4.1/mingw_64/mkspecs/win32-g++/qmake.conf:
D:/QT/6.4.1/mingw_64/mkspecs/features/spec_post.prf:
.qmake.stash:
D:/QT/6.4.1/mingw_64/mkspecs/features/exclusive_builds.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/toolchain.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/default_pre.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/win32/default_pre.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/resolve_config.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/exclusive_builds_post.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/default_post.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/qml_debug.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/entrypoint.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/precompile_header.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/warn_on.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/qt.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/resources_functions.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/resources.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/moc.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/win32/opengl.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/uic.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/qmake_use.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/file_copies.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/win32/windows.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/testcase_targets.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/exceptions.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/yacc.prf:
D:/QT/6.4.1/mingw_64/mkspecs/features/lex.prf:
CrucisIPC.pro:
D:/QT/6.4.1/mingw_64/lib/Qt6Svg.prl:
D:/QT/6.4.1/mingw_64/lib/Qt6Widgets.prl:
D:/QT/6.4.1/mingw_64/lib/Qt6Gui.prl:
D:/QT/6.4.1/mingw_64/lib/Qt6Core.prl:
D:/QT/6.4.1/mingw_64/lib/Qt6EntryPoint.prl:
D:/QT/6.4.1/mingw_64/mkspecs/features/build_pass.prf:
icons.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile CrucisIPC.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

.SUFFIXES:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
