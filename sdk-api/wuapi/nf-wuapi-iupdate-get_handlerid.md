# IUpdate::get_HandlerID

## Description

Gets the install handler of the update.

This property is read-only.

## Parameters

## Remarks

The valid values for the **HandlerID** property include the following:

* The Command Line Installation Handlerhttp://schemas.microsoft.com/msus/2002/12/UpdateHandlers/CommandLineInstallation
* The Inf Based Installation Handlerhttp://schemas.microsoft.com/msus/2002/12/UpdateHandlers/InfBasedInstallation
* The [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) Installation Handlerhttp://schemas.microsoft.com/msus/2002/12/UpdateHandlers/WindowsInstaller
* The Package Installer for Microsoft Windows Operating Systems and Windows Components (update.exe) Installation Handlerhttp://schemas.microsoft.com/msus/2002/12/UpdateHandlers/WindowsPatch
* The Component Based Servicing (CBS) Handlerhttp://schemas.microsoft.com/msus/2002/12/UpdateHandlers/Cbs

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)