# IWTSVirtualChannelCallback::OnDataReceived

## Description

Notifies the user about data that is being received.

The data has the same size and content as a corresponding [WTSVirtualChannelWrite()](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelwrite) call from the remote side. There is no hard limit on the size of the data that can be sent. All packet reconstruction is handled by the dynamic virtual channel (DVC) framework.

## Parameters

### `cbSize` [in]

The size, in bytes, of the buffer to receive the data.

### `pBuffer` [in]

A pointer to a buffer to receive the data. This buffer is valid only until this call is complete.

## Return value

Returns **S_OK** on success. Results in no action if the call fails.

## See also

[IWTSVirtualChannelCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback)