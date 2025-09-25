# IInstallationProgress::GetUpdateResult

## Description

Returns the result of the installation or uninstallation of a specified update.

## Parameters

### `updateIndex` [in]

A zero-based index value that specifies an update.

### `retval` [out]

An [IUpdateInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstallationresult) interface that contains information about a specified update.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

You must make repeated calls to the **GetUpdateResult** method to track the progress of a download. You must do this because
the [IUpdateInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstallationresult) interface is not automatically updated during a download.

## See also

[IInstallationProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogress)