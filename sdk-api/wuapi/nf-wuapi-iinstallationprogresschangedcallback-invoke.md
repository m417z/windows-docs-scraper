# IInstallationProgressChangedCallback::Invoke

## Description

Handles the notification of the change in the progress of an asynchronous installation or uninstallation that was initiated by a call to the [IUpdateInstaller.BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall) method or the [IUpdateInstaller.BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall) method.

## Parameters

### `installationJob` [in]

An [IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob) interface that contains the installation information.

### `callbackArgs` [in]

An [IInstallationProgressChangedCallbackArgs](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogresschangedcallbackargs) interface that contains the installation progress data.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IInstallationProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogresschangedcallback)

[IUpdateInstaller::BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall)