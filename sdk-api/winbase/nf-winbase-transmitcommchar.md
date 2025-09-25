# TransmitCommChar function

## Description

Transmits a specified character ahead of any pending data in the output buffer of the specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `cChar` [in]

The character to be transmitted.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**TransmitCommChar** function is useful for sending an interrupt character (such as a CTRL+C) to a host system.

If the device is not transmitting,
**TransmitCommChar** cannot be called repeatedly. Once
**TransmitCommChar** places a character in the output buffer, the character must be transmitted before the function can be called again. If the previous character has not yet been sent,
**TransmitCommChar** returns an error.

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)