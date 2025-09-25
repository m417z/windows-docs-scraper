# UcxRootHubPortChanged function

## Description

Notifies UCX about a new port change event on the host controller.

## Parameters

### `UcxRootHub` [in]

A handle to the root hub object. The client driver retrieved the handle in a previous call to [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85)).

## Remarks

This method causes interrupt transfers to be sent to the host controller. UCX invokes the client driver's implementation of the [EVT_UCX_ROOTHUB_INTERRUPT_TX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_interrupt_tx) event callback.

## See also

[UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))