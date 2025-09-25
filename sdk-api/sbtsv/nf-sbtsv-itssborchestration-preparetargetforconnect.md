# ITsSbOrchestration::PrepareTargetForConnect

## Description

Prepares the target for a client connection.

## Parameters

### `pConnection` [in]

 A pointer to an [ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection) client connection object.

### `pOrchestrationNotifySink` [in]

A pointer to an [ITsSbOrchestrationNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestrationnotifysink) orchestration notify sink object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is particularly useful for plug-ins that redirect users to virtual desktops. Remote Desktop Connection Broker (RD Connection Broker)
calls this method after placement has successfully completed. Orchestration can
include waking a virtual machine and determining its IP address. Your implementation of this method should ensure that the target is ready to accept a client connection.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)

[ITsSbOrchestration](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestration)

[ITsSbOrchestrationNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestrationnotifysink)