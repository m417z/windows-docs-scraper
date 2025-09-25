# IWTSPlugin::Disconnected

## Description

Notifies the plug-in that the Remote Desktop Connection (RDC) client has disconnected from the Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `dwDisconnectCode` [in]

Code that identifies the disconnect reason. For the possible codes, see [IMsTscAxEvents::OnDisconnected](https://learn.microsoft.com/windows/desktop/TermServ/imstscaxevents-ondisconnected).

## Return value

Returns **S_OK** if the call completes successfully. Results in no action if the call fails.

## See also

[IWTSPlugin](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsplugin)