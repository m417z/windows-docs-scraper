# UcxControllerSetFailed function

## Description

Informs USB Host Controller Extension (UCX) that the controller has encountered a critical failure.

## Parameters

### `Controller` [in]

A handle to the controller object. The client driver retrieved the handle in a previous call to [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)).

## Remarks

 The client driver for host controller must call this function if the driver fails D0 entry or the driver has stopped processing transfers to or from an endpoint.

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))