# IInstallationJob::GetProgress

## Description

Returns an [IInstallationProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogress) interface that describes the current progress of an installation or uninstallation.

## Parameters

### `retval` [out]

An [IInstallationProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationprogress) interface that describes the current progress of an installation or uninstallation.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

You must make repeated calls to the **GetProgress** method to track the progress of a download. You must do this because
the [IUpdateInstallationResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstallationresult) interface is not automatically updated during a download.

## See also

[IInstallationJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationjob)