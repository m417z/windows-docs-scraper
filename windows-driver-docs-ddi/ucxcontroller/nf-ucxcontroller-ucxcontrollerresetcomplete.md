# UcxControllerResetComplete function

## Description

Informs USB host controller extension (UCX) that the reset operation has competed.

## Parameters

### `Controller` [in]

A handle to the controller object to reset. The client driver retrieved the handle in a previous call to [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)).

### `UcxControllerResetCompleteInfo`

Pointer to information about the UCX controller state after the reset completes.

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)