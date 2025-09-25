# IWTSVirtualChannel::Close

## Description

Closes the channel.

If the channel has not already been closed, the **Close()** method will call the [IWTSVirtualChannelCallback::OnClose()](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannelcallback-onclose) method into the associated virtual channel callback interface. After a channel is closed, any [Write()](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-write) call on it will fail.

## Return value

Returns **S_OK** if successful.

## See also

[IWTSVirtualChannel](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannel)