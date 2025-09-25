# ITsSbPluginNotifySink::OnTerminated

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the plug-in has completed a call of [Terminate](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbplugin-terminate).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins should call this method after they complete their termination process or after throwing a fatal exception.

## See also

[ITsSbPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginnotifysink)