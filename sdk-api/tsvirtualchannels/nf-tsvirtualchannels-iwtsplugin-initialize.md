# IWTSPlugin::Initialize

## Description

Used for the first call that is made from the client to the plug-in. Any plug-in initialization should occur in this interface. Initialization occurs only once per plug-in.

## Parameters

### `pChannelMgr` [in]

Passed instance to the channel manager ([IWTSVirtualChannelManager](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsvirtualchannelmanager)) for the client.

## Return value

Returns **S_OK** if the call completes successfully. If the call fails, the plug-in will be released by the Remote Desktop Connection (RDC) client.

## See also

[IWTSPlugin](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsplugin)