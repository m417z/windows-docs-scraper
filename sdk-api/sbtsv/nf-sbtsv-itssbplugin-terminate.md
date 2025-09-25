# ITsSbPlugin::Terminate

## Description

Performs clean-up and unloads the plug-in. Remote Desktop Connection Broker (RD Connection Broker) calls this method when it stops the RD Connection Broker service.

## Parameters

### `hr` [in]

Specifies the reason for termination. The plug-in should specify a standard **HRESULT** error code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbLoadBalancing](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbloadbalancing)

[ITsSbOrchestration](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestration)

[ITsSbPlacement](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacement)

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[ITsSbProvisioning](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioning)

[ITsSbResourcePlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourceplugin)

[ITsSbTaskPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskplugin)