# _DXGK_POWER_COMPONENT_FLAGS structure

## Description

Describes state transition information about a power component.

## Members

### `Reserved0`

Reserved for system use and should be set to zero.

### `DriverCompletesFStateTransition`

If set, indicates that the display miniport driver will call the [DxgkCbCompleteFStateTransition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_completefstatetransition) function for a registered power component when the component completes an F-state transition.

For more information, see Remarks section of the [DxgkCbCompleteFStateTransition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_completefstatetransition) function.

### `TransitionTo_F0_OnDx`

If set, indicates that the Windows power management framework will place a registered power component into the F0 power state during device power state (Dx) transitions.

If set, during a Dx transition the power manager places the component into the F0 state before it dispatches a Dx IRP to the device stack. The power manager keeps the component in the F0 state until the D0 IRP is completed.

### `NoDebounce`

### `ActiveInD3`

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that **DXGK_POWER_COMPONENT_FLAGS** contains that can hold a 32-bit value that identifies information about the power component.

## See also

[DxgkCbCompleteFStateTransition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_completefstatetransition)