# IInstallationJob::get_AsyncState

## Description

Gets the caller-specific state object that is passed to the [IUpdateInstaller.BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall) method or to the [IUpdateInstaller.BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall) method.

This property is read-only.

## Parameters

## Remarks

This state object can be used by the caller to identify a particular download or to pass information from the caller to the implementation of the [IInstallationProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogresschangedcallback) interface or the [IInstallationCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationcompletedcallback) interface.

## See also

[IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob)