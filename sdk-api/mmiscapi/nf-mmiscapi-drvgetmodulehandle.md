# DrvGetModuleHandle function

## Description

Retrieves the instance handle of the module that contains the installable driver. This function is provided for compatibility with previous versions of Windows.

## Parameters

### `hDriver` [in]

Handle of the installable driver instance. The handle must have been previously created by using the [OpenDriver](https://learn.microsoft.com/previous-versions/dd743639(v=vs.85)) function.

## Return value

Returns an instance handle of the driver module if successful or **NULL** otherwise.

## See also

[Installable Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/installable-driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)