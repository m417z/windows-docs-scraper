# NdisMDeregisterMiniportDriver function

## Description

A miniport driver calls the
**NdisMDeregisterMiniportDriver** function to release resources that it allocated with a previous call to
the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

## Parameters

### `NdisMiniportDriverHandle` [in]

The handle that the miniport driver obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

## Remarks

If an error occurs in the miniport driver's
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine after the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function returns successfully, the driver must call
**NdisMDeregisterMiniportDriver** before
**DriverEntry** returns. If
**DriverEntry** succeeds, the driver must call
**NdisMDeregisterMiniportDriver** from its
[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload) function.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)