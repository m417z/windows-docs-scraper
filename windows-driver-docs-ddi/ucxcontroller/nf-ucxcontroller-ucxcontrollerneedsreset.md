# UcxControllerNeedsReset function

## Description

Initiates a non-Plug and Play (PnP) controller reset operation by queuing an event into the controller reset state machine.

## Parameters

### `Controller` [in]

A handle to the controller object to reset. The client driver retrieved the handle in a previous call to [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate).

## Remarks

If the operation is successful, the method returns TRUE. Otherwise, it returns FALSE.

## See also

- [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate)