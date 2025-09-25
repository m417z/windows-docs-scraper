# NdisCompleteUnbindAdapterEx function

## Description

A protocol driver calls the
**NdisCompleteUnbindAdapterEx** function to complete an unbind operation for which the driver's
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function
returned NDIS_STATUS_PENDING.

## Parameters

### `UnbindContext` [in]

The handle that NDIS passed to the
*UnbindContext* parameter of the
*ProtocolUnbindAdapterEx* function.

## Remarks

When a protocol driver returns NDIS_STATUS_PENDING from its
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function, that driver must call
**NdisCompleteUnbindAdapterEx** after the unbind operation is completed.

When the driver calls
**NdisCompleteUnbindAdapterEx**, the driver has finished cleaning up any per-binding context
information that the driver maintains for the binding, and released any resources that it allocated to
establish the binding.

On return from
**NdisCompleteUnbindAdapterEx** the
*UnbindContext* handle is invalid. That is, the protocol driver should not pass this handle in calls
to any
**Ndis*Xxx*** function.

## See also

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)