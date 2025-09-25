# SetCommState function

## Description

Configures a communications device according to the specifications in a device-control block (a
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure). The function reinitializes all hardware and control settings, but it does not empty output or input queues.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpDCB` [in]

A pointer to a
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure that contains the configuration information for the specified communications device.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetCommState** function uses a
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure to specify the desired configuration. The
[GetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommstate) function returns the current configuration.

To set only a few members of the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure, you should modify a
**DCB** structure that has been filled in by a call to
[GetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommstate). This ensures that the other members of the
**DCB** structure have appropriate values.

The
**SetCommState** function fails if the **XonChar** member of the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure is equal to the **XoffChar** member.

When
**SetCommState** is used to configure the 8250, the following restrictions apply to the values for the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure's **ByteSize** and **StopBits** members:

The number of data bits must be 5 to 8 bits.

#### Examples

For an example, see
[Configuring a Communications Resource](https://learn.microsoft.com/windows/desktop/DevIO/configuring-a-communications-resource).

## See also

[BuildCommDCB](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-buildcommdcba)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[GetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommstate)