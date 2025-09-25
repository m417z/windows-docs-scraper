# ITsSbOrchestrationNotifySink::OnReadyToConnect

## Description

Returns an [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) object to Remote Desktop Connection Broker (RD Connection Broker) after the target is successfully prepared for a connection.

## Parameters

### `pTarget` [in]

A pointer to an [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) target object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The target object referenced by the *pTarget* parameter should contain the external IP address of the target object. Without this information, the request will fail.

## See also

[ITsSbOrchestrationNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssborchestrationnotifysink)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)