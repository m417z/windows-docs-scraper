# IUpdateInstaller::Install

## Description

Starts a synchronous installation of the updates.

## Parameters

### `retval` [out]

An [IInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationresult) interface that represents the results of an installation operation for each update that is specified in a request.

## Return value

This method returns the following **HRESULT** values and other COM or Windows

error codes.

| Return code | Description |
| --- | --- |
| **S_OK** | The update was installed successfully. |
| **WU_E_INSTALL_NOT_ALLOWED** | Do not call this method when the installer is installing or removing an update. <br><br>Call this method only when the [IsBusy](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_isbusy) property of the [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) interface returns **VARIANT_FALSE**. |
| **WU_E_NO_UPDATE** | There are no updates in a collection. |

## Remarks

This method returns WU_E_NO_UPDATE if the [Updates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_updates) property of [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) is not set. This method also returns WU_E_NO_UPDATE if the **Updates** property is set to an empty collection.

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)