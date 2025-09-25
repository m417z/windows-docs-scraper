# NdisCompleteBindAdapterEx function

## Description

A protocol driver calls the
**NdisCompleteBindAdapterEx** function to complete a binding operation for which the driver's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function
returned NDIS_STATUS_PENDING.

## Parameters

### `BindAdapterContext`

The handle that NDIS passed to the
*BindContext* parameter of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

### `Status` [in]

The final status of the completed bind operation. This parameter can be one of the following
values:

#### NDIS_STATUS_SUCCESS

The driver successfully completed the binding to the underlying NIC.

#### NDIS_STATUS_XXX or NTSTATUS_XXX

The protocol driver's attempt to set up a binding failed or the protocol driver could not
allocate the resources it needed to carry out network I/O operations. Usually, such an error status is
propagated from an
**Ndis*Xxx*** function or a kernel-mode support routine.

## Remarks

If a protocol driver returns NDIS_STATUS_PENDING from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function,
that driver must call
**NdisCompleteBindAdapterEx** after the binding operation is completed.

If the open operation was successful, the protocol driver is ready to accept receive indications from
underlying drivers and to initiate send requests and OID requests on the binding. If the driver calls
**NdisCompleteBindAdapterEx** with an error status, the binding attempt failed and the driver has
released any resources it allocated to establish the binding.

## See also

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)