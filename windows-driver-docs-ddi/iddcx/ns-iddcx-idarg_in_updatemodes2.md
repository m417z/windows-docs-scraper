## Description

The **IDARG_IN_UPDATEMODES2** structure contains input parameters for the [**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2) function.

## Members

### `Reason`

[in] An [**IDDCX_UPDATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_update_reason) value that indicates the reason why the driver is updating the modes.

### `TargetModeCount`

[in] Number of target modes in the buffer that **pTargetModes** points to. **TargetModeCount** can't be zero.

### `pTargetModes`

[in] Pointer to a [**IDDCX_TARGET_MODE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_target_mode2) structure that contains the target modes the driver supports for this monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDDCX_TARGET_MODE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_target_mode2)

[**IDDCX_UPDATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_update_reason)

[**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)