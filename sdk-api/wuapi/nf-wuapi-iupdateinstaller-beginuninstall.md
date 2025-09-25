# IUpdateInstaller::BeginUninstall

## Description

Starts an asynchronous uninstallation of the updates.

## Parameters

### `onProgressChanged` [in]

An [IInstallationProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogresschangedcallback) interface that is called periodically for uninstallation progress changes before the uninstallation is complete.

### `onCompleted` [in]

An [IInstallationCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationcompletedcallback) interface that is called when an installation operation is complete.

### `state` [in]

The caller-specific state that the [AsyncState](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iinstallationjob-get_asyncstate) property [IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob) interface returns.

### `retval` [out]

An [IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob) interface that contains the properties and methods that are available to an asynchronous uninstall operation that was initiated.

## Return value

This method returns the following **HRESULT** values and other COM or Windows

error codes.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The asynchronous removal of an update started successfully. |
| **WU_E_INSTALL_NOT_ALLOWED** | Do not call this method when the installer is installing or removing an update. <br><br>Call this method only when the [IsBusy](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_isbusy) property of the [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) interface returns **VARIANT_FALSE**. |
| **WU_E_NO_UPDATE** | Windows Update Agent (WUA) does not have updates in the collection. |

## Remarks

 If you call this method from a scripting language, set the *onProgressChanged* parameter to the identifier of an Automation object with a dispatch identifier (DSIPID) of zero (0) that implements the callback routine. Do the same thing for the *onCompleted* parameter.

This method returns WU_E_NO_UPDATE if the [Updates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_updates) property of [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) is not set. This method also returns WU_E_NO_UPDATE if the **Updates** property is set to an empty collection.

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)