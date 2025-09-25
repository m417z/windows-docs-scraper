# NdisReEnumerateProtocolBindings function

## Description

The
**NdisReEnumerateProtocolBindings** function causes NDIS to call a protocol driver's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function one
time for each miniport adapter for which the driver is configured to bind but to which the driver is not
currently bound.

## Parameters

### `NdisProtocolHandle` [in]

A handle representing the calling protocol driver. The driver obtained this handle with a previous
call to the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

## Remarks

A protocol driver can call the
**NdisReEnumerateProtocolBindings** function to rebind to one or more miniport adapters.

Protocol drivers cannot call
**NdisReEnumerateProtocolBindings** from within the context of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex), or
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) functions. Also, protocol drivers cannot call
**NdisReEnumerateProtocolBindings** from within the context of the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function if the
*ProtocolBindingContext* parameter of
*ProtocolNetPnPEvent* is not **NULL**. However, protocol drivers can call
**NdisReEnumerateProtocolBindings** from within the context of
*ProtocolNetPnPEvent* if
*ProtocolBindingContext* is **NULL**. A **NULL***ProtocolBindingContext* value indicates that the event applies to all bindings.

NDIS might complete the binding operations after the call to
**NdisReEnumerateProtocolBindings** returns. That is, NDIS might complete bindings to the miniport
adapters for which the protocol driver is configured to bind but to which the protocol driver is not
currently bound at a later time.

An intermediate driver should call
**NdisReEnumerateProtocolBindings** after its
*ProtocolNetPnPEvent* function receives
**NetEventReconfigure** on a **NULL***ProtocolBindingContext* . NDIS then calls the driver's
*ProtocolBindAdapterEx* function one time for each miniport adapter for which the driver is
configured to bind but to which the driver is not currently bound.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550472(v=vs.85))

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)