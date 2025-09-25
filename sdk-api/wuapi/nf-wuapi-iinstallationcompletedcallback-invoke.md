# IInstallationCompletedCallback::Invoke

## Description

Handles the notification of the completion of an asynchronous installation or uninstallation that is initiated by a call to [IUpdateInstaller.BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall) or [IUpdateInstaller.BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall).

## Parameters

### `installationJob` [in]

An [IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob) interface that contains the installation information.

### `callbackArgs` [in]

This parameter is reserved for future use and can be ignored.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IInstallationCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationcompletedcallback)

[IUpdateInstaller::BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall)