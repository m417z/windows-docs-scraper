# WTSVirtualChannelRead function

## Description

Reads data from the server end of a virtual
channel.

**WTSVirtualChannelRead** reads the data written
by a [VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) call at the client
end of the virtual channel.

## Parameters

### `hChannelHandle` [in]

Handle to a virtual channel opened by the
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen) function.

### `TimeOut` [in]

Specifies the time-out, in milliseconds. If *TimeOut* is zero,
**WTSVirtualChannelRead** returns immediately
if there is no data to read. If *TimeOut* is INFINITE (defined in Winbase.h), the
function waits indefinitely until there is data to read.

### `Buffer` [out]

Pointer to a buffer that receives a chunk of data read from the server end of the virtual channel. The maximum
amount of data that the server can receive in a single
**WTSVirtualChannelRead** call is
**CHANNEL_CHUNK_LENGTH** bytes. If the client's
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) call writes
a larger block of data, the server must make multiple
**WTSVirtualChannelRead** calls.

In certain cases, Remote Desktop Services places a
**CHANNEL_PDU_HEADER** structure at the beginning of each chunk of data read by the
**WTSVirtualChannelRead** function. This will occur if the
client DLL sets the **CHANNEL_OPTION_SHOW_PROTOCOL** option when it calls the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function to initialize the virtual channel. This will also occur if the channel is a dynamic virtual channel written to by using the [IWTSVirtualChannel::Write](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-write) method. Otherwise,
the buffer receives only the data written in the
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) call.

### `BufferSize` [in]

Specifies the size, in bytes, of *Buffer*. If the chunk of data in *Buffer* will be preceded by a **CHANNEL_PDU_HEADER** structure, the value of this parameter should be at least
**CHANNEL_PDU_LENGTH**. Otherwise, the value of this parameter should be at least **CHANNEL_CHUNK_LENGTH**.

### `pBytesRead` [out]

Pointer to a variable that receives the number of bytes read.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** **WTSVirtualChannelRead** is not thread safe.
To access a virtual channel from multiple threads, or to do asynchronous IO through a virtual channel, use
[WTSVirtualChannelQuery](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelquery) with
**WTSVirtualFileHandle**.

## See also

[CHANNEL_PDU_HEADER](https://learn.microsoft.com/windows/desktop/api/pchannel/ns-pchannel-channel_pdu_header)

[IWTSVirtualChannel::Write](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-write)

[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite)

[WTSVirtualChannelQuery](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelquery)

[WTSVirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelwrite)