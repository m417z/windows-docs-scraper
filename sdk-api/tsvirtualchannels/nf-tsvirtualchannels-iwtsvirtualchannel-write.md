# IWTSVirtualChannel::Write

## Description

Starts a write request on the channel. All writes are considered asynchronous. Calling this method copies the contents of *pBuffer* and returns immediately, so the buffer can be reclaimed. Because of the memory copy, too many **Write()** calls may result in allocating too much memory by the client.

A [Close()](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-close) call on this channel will cancel any pending writes.

When using the RDP stack, there is a max limit of 1590 bytes that can be written per call to this function. The call will not fail if this limit is exceeded. More specific details on the limit can be found in the DVC protocol spec [2.2.3.1 DVC Data First PDU (DYNVC_DATA_FIRST)](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpedyc/69377767-56a6-4ab8-996b-7758676e9261)

## Parameters

### `cbSize` [in]

The size, in bytes, of the buffer to which to write.

### `pBuffer` [in]

A pointer to a buffer on the channel to which to write the data. You can reuse this buffer as soon as the call returns.

### `pReserved` [in, optional]

Reserved for future use. The value must be **NULL**.

## Return value

Returns **S_OK** if successful.

## See also

[IWTSVirtualChannel](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannel)