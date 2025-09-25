# NdisMIndicateStatusEx function

## Description

The
**NdisMIndicateStatusEx** function reports a change in the status of a miniport adapter.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed at the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

When a miniport driver calls
**NdisMIndicateStatusEx**, NDIS calls each bound protocol driver's
[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function. This allows
a bound protocol driver to log the change in status of an underlying miniport adapter or to take
action.

A miniport driver can call
**NdisMIndicateStatusEx** after setting its registration attributes even if the driver is still in the
context of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The
driver must not call
**NdisMIndicateStatusEx** after it returns from the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)