# _UCX_CONTROLLER_RESET_COMPLETE_INFO structure

## Description

Contains information about the operation to reset the controller. This is used by the client driver in its [EVT_UCX_CONTROLLER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_reset) callback function.

## Members

### `Size`

The size in bytes of this structure.

### `UcxControllerState`

The UCX controller state after reset.

### `UcxCoordinated`

Indicates if the reset was coordinated with UCX (TRUE) or not (FALSE).

## Remarks

This structure is populated by a call to [UcxControllerResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollerresetcomplete).