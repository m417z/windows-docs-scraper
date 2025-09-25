# NdisFRestartComplete function

## Description

A filter driver must call the
**NdisFRestartComplete** function to complete a restart operation if the driver returned
NDIS_STATUS_PENDING from its
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `Status` [in]

The final status of the restart operation. The following status values are supported:

#### NDIS_STATUS_SUCCESS

The driver successfully restarted the flow of network data.

#### NDIS_STATUS_RESOURCES

The restart failed because of insufficient resources.

#### NDIS_STATUS_FAILURE

The driver indicates NDIS_STATUS_FAILURE if none of the preceding values applies. The driver
should call the
[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry) function
together with parameters that specify the reason for the failure.

## Remarks

NDIS calls a filter driver's
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function to initiate a
restart request for filter module. The filter module remains in the
*Restarting* state until the restart operation is complete.

A pending restart operation is complete after the driver calls the
**NdisFRestartComplete** function. The filter module is in the
*Running* state after the restart operation is complete.

A filter driver can resume indicating received network data immediately after NDIS calls
*FilterRestart* and before the driver calls
**NdisFRestartComplete**. The driver should be ready to accept send requests after it completes the
restart operation.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)