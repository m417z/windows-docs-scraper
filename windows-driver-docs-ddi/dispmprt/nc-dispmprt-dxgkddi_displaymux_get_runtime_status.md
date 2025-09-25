## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkDdiDisplayMuxGetRuntimeStatus** function to query the runtime level of automatic display switch (ADS) support that the driver provides.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `pRuntimeStatus`

[out] Pointer to a [**DXGK_DISPLAYMUX_RUNTIME_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_displaymux_runtime_status) value in which the driver writes the runtime status of ADS support that it provides.

## Return value

**DxgkDdiDisplayMuxGetRuntimeStatus** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NT_STATUS error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

**DxgkDdiDisplayMuxGetRuntimeStatus** is called after [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device). It allows KMD to indicate that it can't support ADS on this system for some reason. The driver shouldn't attempt to query information about other GPUs in the system or communicate with the ACPI mux device.

If the driver sets **pRuntimeStatus** to point to DXGK_DISPLAYMUX_RUNTIME_STATUS_NON_CRITICAL_SYSTEM_INFO_MISSING, the system will enable ADS for developmental purposes only; that is, ADS will not be enabled for customer use.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DXGK_DISPLAYMUX_RUNTIME_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_displaymux_runtime_status)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)