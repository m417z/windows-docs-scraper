# GetCommProperties function

## Description

Retrieves information about the communications properties for a specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpCommProp` [out]

A pointer to a
[COMMPROP](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commprop) structure in which the communications properties information is returned. This information can be used in subsequent calls to the
[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate),
[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts), or
[SetupComm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setupcomm) function to configure the communications device.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetCommProperties** function returns information from a device driver about the configuration settings that are supported by the driver.

## See also

[COMMPROP](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commprop)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate)

[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts)

[SetupComm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setupcomm)