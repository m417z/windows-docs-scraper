# NdisFPauseComplete function

## Description

A filter driver must call the
**NdisFPauseComplete** function to complete a pause operation if the driver returned NDIS_STATUS_PENDING
from its
[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause) function.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

## Remarks

NDIS calls a filter driver's
[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause) function to initiate a pause
request for a filter module. The filter module remains in the
*Pausing* state until the pause operation is complete.

After a pending pause operation is complete, the driver calls
**NdisFPauseComplete** to notify NDIS. After the driver calls
**NdisFPauseComplete**, the filter module is in the
*Paused* state.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause)