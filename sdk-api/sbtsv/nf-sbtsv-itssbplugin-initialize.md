# ITsSbPlugin::Initialize

## Description

Initializes the plug-in.

Remote Desktop Connection Broker (RD Connection Broker) calls this method immediately after the RD Connection Broker service starts. Plug-ins can use this method to add information about existing environments and targets in the RD Connection Broker store.

[ITsSbResourcePlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourceplugin)
[ITsSbLoadBalancing](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancing)
[ITsSbPlacement](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacement)
[ITsSbOrchestration](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestration)
[ITsSbTaskPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskplugin)

## Parameters

### `pProvider` [in]

A pointer to an [ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider) provider object.

### `pNotifySink` [in]

A pointer to an [ITsSbPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginnotifysink) notify sink object.

### `pPropertySet` [in]

A pointer to an [ITsSbPluginPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginpropertyset) plug-in property set object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins should call [OnInitialized](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbpluginnotifysink-oninitialized) on the specified [ITsSbPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginnotifysink) sink object.

## See also

[ITsSbLoadBalancing](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancing)

[ITsSbOrchestration](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestration)

[ITsSbPlacement](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacement)

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[ITsSbPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginnotifysink)

[ITsSbPluginPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginpropertyset)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbProvisioning](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioning)

[ITsSbResourcePlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourceplugin)

[ITsSbTaskPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskplugin)