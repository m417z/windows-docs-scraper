# NdisMRestartComplete function

## Description

A miniport driver must call the
**NdisMRestartComplete** function to complete a restart operation if the driver returned
NDIS_STATUS_PENDING from its
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `Status` [in]

The final status of the restart operation. The following status values are supported:

#### NDIS_STATUS_SUCCESS

The driver successfully restarted the flow of network data through the miniport adapter.

#### NDIS_STATUS_RESOURCES

The restart failed because of insufficient resources.

#### NDIS_STATUS_FAILURE

The driver indicates NDIS_STATUS_FAILURE if none of the preceding values applies. The driver
should call the
[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function
with parameters that specify the reason for the failure.

## Remarks

The miniport adapter specified at
*MiniportAdapterHandle* enters the
*Restarting* state when NDIS calls the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function.

After the miniport driver successfully restarts the send and receive operations for the miniport
adapter, the driver must complete the pending restart operation. The pending restart operation is
complete after the driver calls
**NdisMRestartComplete**. The miniport adapter is in the
*Running* state after the restart operation is complete.

A miniport driver can resume indicating received packets immediately after NDIS calls
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) and before the driver calls
**NdisMRestartComplete**. The driver should be ready to accept send requests after it completes the
restart request.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)