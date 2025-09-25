# IWTSPlugin::Terminated

## Description

Notifies the plug-in that the Remote Desktop Connection (RDC) client has terminated. After a call is made to **IWTSPlugin::Terminated**, no other calls to the plug-in are expected. Any plug-in cleanup should be done here.

## Return value

Returns **S_OK** if the call completes successfully. Results in no action if the call fails.

## See also

[IWTSPlugin](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsplugin)