# IWTSListenerCallback::OnNewChannelConnection

## Description

Allows the Remote Desktop Connection (RDC) client plug-in to accept or deny a connection request for an
incoming connection.

## Parameters

### `pChannel` [in]

An [IWTSVirtualChannel](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback) object that
represents the incoming connection. This object will only be connected if the connection is accepted by this
method.

### `data` [in]

This parameter is not implemented and is reserved for future use.

### `pbAccept` [out]

Indicates whether the connection should be accepted. Receives **TRUE** if the
connection should be accepted or **FALSE** otherwise.

### `ppCallback` [out]

Receives an
[IWTSVirtualChannelCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback) object that
receives notifications for the connection. This object is created by the plug-in.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DVC Client Plug-in Example](https://learn.microsoft.com/windows/desktop/TermServ/dvc-client-plug-in-example)

[IWTSListenerCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistenercallback)

[IWTSVirtualChannel](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback)

[IWTSVirtualChannelCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelcallback)