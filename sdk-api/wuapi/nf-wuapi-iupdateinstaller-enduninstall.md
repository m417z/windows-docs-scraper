# IUpdateInstaller::EndUninstall

## Description

Completes an asynchronous uninstallation of the updates.

## Parameters

### `value` [in]

The [IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob) interface that the [BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall) method returns.

### `retval` [out]

An [IInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationresult) interface that represents the overall result of an uninstallation operation.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

## Remarks

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)