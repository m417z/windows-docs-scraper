# NdisIMAssociateMiniport function

## Description

The
**NdisIMAssociateMiniport** function informs NDIS that the specified lower and upper interfaces for
miniport and protocol drivers respectively belong to the same intermediate driver.

## Parameters

### `DriverHandle` [in]

The handle to the miniport driver interface that the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function returns.

### `ProtocolHandle` [in]

The handle to the protocol interface that the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function returns.

## Remarks

Any NDIS intermediate driver that exports both
*MiniportXxx* and
*ProtocolXxx* functions calls
**NdisIMAssociateMiniport** to inform the NDIS library about its miniport upper edge and its protocol
lower edge. Such an intermediate driver calls
**NdisIMAssociateMiniport** during its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. For more information about
**DriverEntry**, see
[DriverEntry of NDIS
Intermediate Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver).

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)