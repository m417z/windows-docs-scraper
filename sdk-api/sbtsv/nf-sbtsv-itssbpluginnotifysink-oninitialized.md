# ITsSbPluginNotifySink::OnInitialized

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the plug-in has completed a call of [Initialize](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbplugin-initialize).

## Parameters

### `hr` [in]

Specifies the result of the call to [Initialize](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbplugin-initialize).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins should call this method after they complete their initialization process.

## See also

[ITsSbPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginnotifysink)