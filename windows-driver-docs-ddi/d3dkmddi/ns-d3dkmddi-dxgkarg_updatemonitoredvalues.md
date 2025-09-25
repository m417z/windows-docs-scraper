## Description

**DXGKARG_UPDATEMONITOREDVALUES** is the parameter for the [**DxgkDdiUpdateMonitoredValues**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatemonitoredvalues) function.

## Members

### `NativeFenceArray`

[in] Array of native fence handles.

### `UpdatedValueArray`

[in] Array of new monitored values.

### `MonitoredValueKernelCpuVa`

[in] Read/write kernel-mode CPU virtual address of the monitored value.

### `NumFences`

[in] Number of native fences that the OS updates monitored values of.

### `Flags`

[in] A [**DXGKARG_UPDATEMONITOREDVALUES_FLAGS **](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatemonitoredvalues_flags) value that specifies the flags for the update.

### `Reserved[28]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiUpdateMonitoredValues**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatemonitoredvalues)