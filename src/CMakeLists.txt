add_definitions(-DTRANSLATION_DOMAIN="bluedevil")

add_subdirectory(sendfile)
add_subdirectory(kded)
add_subdirectory(kio)
add_subdirectory(wizard)
add_subdirectory(applet)
add_subdirectory(kcm)

install(FILES bluedevil.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFY5RCDIR})

install(FILES bluedevil-mime.xml DESTINATION ${KDE_INSTALL_MIMEDIR})
update_xdg_mimetypes(${KDE_INSTALL_MIMEDIR})

install(FILES Jbluetooth.svg DESTINATION ${KDE_INSTALL_FULL_ICONDIR}/hicolor/scalable/apps)
