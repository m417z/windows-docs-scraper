# WPUFDIsSet function

## Description

The
**WPUFDIsSet** function checks the membership of the specified socket handle.

## Parameters

### `s` [in]

Descriptor identifying the socket.

### `fdset` [in]

Set to check for the membership of socket *s*.

## Return value

If no error occurs, a value of nonzero is returned denoting that socket *s* is a member of the *set* parameter. Otherwise, the return value is zero.

## See also

[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)