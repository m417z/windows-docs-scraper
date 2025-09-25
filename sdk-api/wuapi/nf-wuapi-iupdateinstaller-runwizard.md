# IUpdateInstaller::RunWizard

## Description

Starts a wizard that guides the local user through the steps to install the updates.

## Parameters

### `dialogTitle` [in, optional]

An optional string value to be displayed in the title bar of the wizard.

If an empty string value is used, the following text is displayed: Download and Install Updates.

### `retval` [out]

An [IInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationresult) interface that represents the results of an installation operation for each update that is specified in the request.

## Return value

This method returns the following **HRESULT** values and other COM or Windows

error codes.

| Return code | Description |
| --- | --- |
| **WU_E_NO_UPDATE** | There are no updates in a collection. |

## Remarks

This method returns WU_E_NO_UPDATE if the [Updates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_updates) property of [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) is not set. This method also returns WU_E_NO_UPDATE if the **Updates** property is set to an empty collection.

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)