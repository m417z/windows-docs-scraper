# NdisMPauseComplete function

## Description

A miniport driver must call the
**NdisMPauseComplete** function to complete a pause operation if the driver returned NDIS_STATUS_PENDING
from its
[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

## Remarks

NDIS calls a miniport driver's
[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function to initiate a
pause request for a miniport adapter. The miniport adapter remains in the
*Pausing* state until the pause operation is complete.

After a miniport driver completes all outstanding send requests and NDIS returns all the network data
structures in outstanding receive indications to the driver, the driver calls
**NdisMPauseComplete** to complete the pending pause request. After the driver calls
**NdisMPauseComplete**, the miniport adapter is in the
*Paused* state.

NDIS calls the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function to initiate a
restart request for a miniport adapter that is paused.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)