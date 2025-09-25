# NdisMCoIndicateStatusEx function

## Description

The
**NdisMCoIndicateStatusEx** function reports a change in the status of a CoNDIS miniport adapter.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed at the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NdisVcHandle` [in, optional]

A handle that identifies the virtual connection (VC). The miniport driver obtained this handle as
an input parameter to its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function, either
when a client set up an outgoing call or when the call manager created a VC for a client-registered
service access point (SAP). The call manager created the VC to indicate an incoming-call notification.
To send the status indication to all protocol bindings, set this parameter to **NULL**.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

When a miniport driver calls
**NdisMCoIndicateStatusEx** with a **NULL** VC handle for the
*NdisVcHandle* parameter, NDIS forwards the status-change notification to all of the bound protocol
drivers by calling each bound protocol driver's
[ProtocolCoStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_status_ex) function. A call
to
**NdisMCoIndicateStatusEx** with a non-**NULL** VC handle restricts the status notification to clients or
call managers that the miniport driver shares this VC handle with.

A miniport driver can call
**NdisMCoIndicateStatusEx** after setting its registration attributes, by calling the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function,
even if the driver is still in the context of the
*MiniportInitializeEx* function. The driver must not call
**NdisMCoIndicateStatusEx** after it returns from the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[ProtocolCoStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_status_ex)