# NdisMResetComplete macro (NDIS 5.x)

## Description

> [!NOTE]
> For NDIS 6.x (Windows Vista and later), use the [NdisMResetComplete function (NDIS 6.x)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete-r1) instead.

The
**NdisMResetComplete** function returns the final status of a reset request for which the miniport driver
previously returned NDIS_STATUS_PENDING.

## Parameters

### `_M`

The miniport adapter handle that NDIS originally passed to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `_S`

The final status of the reset operation just completed. The return values are the same as those listed for the [MINIPORT_RESET callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset).

### `_A`

A Boolean value that is **TRUE** if NDIS is responsible for restoring the settings for multicast
addresses, packet filters, and task offload information. In this case, the miniport driver is
responsible for restoring the rest of the configuration settings for the network interface card (NIC)
referenced by
*MiniportAdapterHandle* .

If
*AddressingReset* is **FALSE**, the miniport driver is responsible for restoring all of the
configuration settings for the NIC.

For more information, see
[Hardware Reset](https://learn.microsoft.com/windows-hardware/drivers/network/hardware-reset).

## Remarks

If the
[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function returns
NDIS_STATUS_PENDING, the miniport driver must call
**NdisMResetComplete** when it completes the reset operation.

Protocol drivers cannot initiate a reset operation in NDIS 6.0 and later versions.

Some NICs lose all multicast address, packet filter, or functional address information when a soft
reset is issued. The driver of such a NIC sets
*AddressingReset* to **TRUE** when it calls
**NdisMResetComplete**, causing NDIS to call its
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function to
restore the addressing state. For more information, see
[Hardware Reset](https://learn.microsoft.com/windows-hardware/drivers/network/hardware-reset).

A miniport driver must release any spin lock that it is holding before calling
**NdisMResetComplete**.

In NDIS 6.0 and later, callers of
**NdisMResetComplete** must run at IRQL <= DISPATCH_LEVEL. Otherwise, callers of
**NdisMResetComplete** must run at IRQL = DISPATCH_LEVEL.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NdisMResetComplete function (NDIS 6.x)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete-r1)