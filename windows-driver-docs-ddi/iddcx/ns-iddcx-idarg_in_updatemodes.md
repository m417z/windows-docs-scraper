# IDARG_IN_UPDATEMODES structure

## Description

The **IDARG_IN_UPDATEMODES** structure contains input parameters for the [**IddCxMonitorUpdateModes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes) function.

## Members

### `Reason`

[in] An [**IDDCX_UPDATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_update_reason) value that indicates the reason why the driver is updating the modes.

### `TargetModeCount`

[in] Number of target modes in the buffer that **pTargetModes** points to. **TargetModeCount** can't be zero.

### `pTargetModes`

[in] Pointer to a [**IDDCX_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_target_mode) structure that contains the target modes the driver supports for this monitor.

## See also

[**IDDCX_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes)

[**IDDCX_UPDATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_update_reason)

[**IddCxMonitorUpdateModes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes)