# WTSVirtualChannelWrite function

## Description

Writes
data to the server end of a virtual channel.

## Parameters

### `hChannelHandle` [in]

Handle to a virtual channel opened by the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.

### `Buffer` [in]

Pointer to a buffer containing the data to write to the virtual channel.

### `Length` [in]

Specifies the size, in bytes, of the data to write.

### `pBytesWritten` [out]

Pointer to a variable that receives the number of bytes written.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** **WTSVirtualChannelWrite** is not thread safe.
To access a virtual channel from multiple threads, or to do asynchronous IO through a virtual channel, use
[WTSVirtualChannelQuery](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelquery) with
**WTSVirtualFileHandle**.

## See also

[WTSVirtualChannelQuery](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelquery)

[WTSVirtualChannelRead](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelread)