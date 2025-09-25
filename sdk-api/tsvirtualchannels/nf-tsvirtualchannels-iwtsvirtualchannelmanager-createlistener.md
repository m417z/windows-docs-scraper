# IWTSVirtualChannelManager::CreateListener

## Description

Returns an instance of a listener object that listens on a specific endpoint.

## Parameters

### `pszChannelName` [in]

The endpoint name on which the listener will listen. This is a string value, the length of which is limited to **MAX_PATH** number of characters.

### `uFlags` [in]

This parameter is reserved and must be set to zero.

### `pListenerCallback` [in, optional]

Returns a listener callback ([IWTSListenerCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistenercallback)) that will receive notifications for incoming connections.

### `ppListener` [out, optional]

An instance of the [IWTSListener](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistener) object.

## Return value

Returns **S_OK** on success.

## See also

[IWTSListener](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistener)

[IWTSListenerCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistenercallback)

[IWTSVirtualChannelManager](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelmanager)