# WTSVirtualChannelClose function

## Description

Closes an open virtual channel handle.

## Parameters

### `hChannelHandle` [in]

Handle to a virtual channel opened by the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen)