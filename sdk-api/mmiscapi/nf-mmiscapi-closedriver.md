# CloseDriver function

## Description

Closes an installable driver.

## Parameters

### `hDriver` [in]

Handle of an installable driver instance. The handle must have been previously created by using the [OpenDriver](https://learn.microsoft.com/previous-versions/dd743639(v=vs.85)) function.

### `lParam1` [in]

32-bit driver-specific data.

### `lParam2` [in]

32-bit driver-specific data.

## Return value

Returns nonzero if successful or zero otherwise.

## Remarks

The function passes the *lParam1* and *lParam2* parameters to the [DriverProc](https://learn.microsoft.com/previous-versions/dd797918(v=vs.85)) function of the installable driver.

## See also

[Installable Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/installable-driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)