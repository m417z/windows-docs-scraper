# NdisMCmNotifyCloseAddressFamily macro

## Description

The
**NdisMCmNotifyCloseAddressFamily** function notifies NDIS that a specified address family (AF) that is
associated with a miniport call manager (MCM) should be closed and NDIS should notify any affected CoNDIS
clients.

## Parameters

### `_AH_`

A handle that identifies the AF that NDIS should close. NDIS supplied this handle to the MCM's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

## Remarks

MCMs, which register as NDIS miniport drivers by calling the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function, can call the
**NdisMCmNotifyCloseAddressFamily** function. Stand-alone call managers instead call the
[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily) function.

To close an AF for a miniport adapter, the MCM should call
**NdisMCmNotifyCloseAddressFamily** from its
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. NDIS
subsequently calls the
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) function of the client that has the specified AF open.

If
**NdisMCmNotifyCloseAddressFamily** returns NDIS_STATUS_PENDING, NDIS calls the MCM's
[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete) function after the client completes the AF close operation.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af)

[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)