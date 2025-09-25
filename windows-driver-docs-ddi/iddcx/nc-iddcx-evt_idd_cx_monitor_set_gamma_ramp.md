# EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP callback function

## Description

The operating system calls **EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP** to set a gamma ramp on the specified monitor.

## Parameters

### `MonitorObject` [in]

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object which is the OS's context handle that identifies the monitor to set a gamma ramp for.

### `pInArgs` [in]

An [**IDARG_IN_SET_GAMMARAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp) structure containing information about the gamma ramp being set.

## Return value

**EVT_IDD_CX_MONITOR_SET_GAMMA_RAMP** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

If a driver reports [FP16 support](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) for an adapter it must also accept and use [**IDDCX_GAMMARAMP_TYPE_3x4_COLORSPACE_TRANSFORM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type) regardless of gamma support previously reported in a call to [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync). This type of gamma ramp can be sent for any monitor even if HDR is not currently being used.

It's possible that some parts of the transform won't be required or have no effect. In this case, the OS will set the appropriate flag to FALSE allowing the driver to potentially use an optimized transform. Like other gamma ramps, the 3x4 transform must also be applied to mouse cursors.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_SET_GAMMARAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_set_gammaramp)

[**IDDCX_GAMMARAMP_TYPE_3x4_COLORSPACE_TRANSFORM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_gammaramp_type)