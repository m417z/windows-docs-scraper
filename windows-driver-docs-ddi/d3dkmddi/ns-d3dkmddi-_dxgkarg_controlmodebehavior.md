# _DXGKARG_CONTROLMODEBEHAVIOR structure

## Description

The DXGKARG_CONTROLMODEBEHAVIOR structure contains the display mode behaviors that the OS requests of the driver and the results of the request.

## Members

### `Request`

A [DXGK_MODE_BEHAVIOR_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_mode_behavior_flags) union containing the behaviors that the OS is requesting.

### `Satisfied`

Flags that report which requests were satisfied. Only flags that were set in the **Request** field and which the driver has been able to apply the requested behavior should be set.

### `NotSatisfied`

Flags that report which requests were not satisfied. Only flags which were set in the **Request** field which the driver supports on this adapter but could not be applied should be set.

## Remarks

If a behavior is not supported, then even if the driver comprehends the behavior, it should leave the flag bit clear in both the **Satisfied** and the **NotSatisfied** fields.

## See also

[DXGK_MODE_BEHAVIOR_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_mode_behavior_flags)

[DXGKDDI_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlmodebehavior)