# WTSVirtualChannelPurgeOutput function

## Description

Deletes all queued output data sent from the server to the client on a specified virtual channel.

**Note** This function currently is not used by Remote Desktop Services.

## Parameters

### `hChannelHandle` [in]

Handle to a virtual channel opened by the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSVirtualChannelPurgeInput](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelpurgeinput)