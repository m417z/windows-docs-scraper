# IInstallationResult::GetUpdateResult

## Description

Returns an [IUpdateInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstallationresult) interface that contains the installation results for a specified update.

## Parameters

### `updateIndex` [in]

The index of an update.

### `retval` [out]

An interface that contains results for a specified update.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

## See also

[IInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationresult)