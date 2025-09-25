# IWTSVirtualChannelCallback::OnClose

## Description

Notifies the user that the channel has been closed. There are three ways for the channel to
be closed:

* The user has called the
  [IWTSVirtualChannel::Close](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-close) method.
* The Remote Desktop Connection (RDC) client has disconnected from the Remote Desktop Session Host (RD Session Host)
  server.
* The server has called the
  [WTSVirtualChannel::Close](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelclose) method on the
  channel.

Regardless of how the channel has been closed, there is no need to call
[IWTSVirtualChannel::Close()](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-close) when this call
is received. If such a call is made, it is possible that if the plug-in is running out of process, that a call to
**IWTSVirtualChannel::Close()** may cause a
deadlock. A deadlock may occur because the caller of
**OnClose()** holds a channel list
lock, and the **Close()** method will try to
acquire the same lock on a different thread.

## Return value

Returns **S_OK** on success. Results in no action if the call fails.

## See also

[IWTSVirtualChannelCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback)