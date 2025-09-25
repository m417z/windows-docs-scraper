## Description

****DXGKARG_UPDATECURRENTVALUESFROMCPU** is the parameter for the [**DxgkDdiUpdateCurrentValuesFromCpu**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatecurrentvaluesfromcpu) function.

## Members

### `NativeFenceArray`

[in] Array of native fence handles.

### `UpdatedValueArray`

[in] Array of new current values.

### `CurrentValueKernelCpuVa`

[in] The read/write kernel-mode CPU virtual address of the current value.

### `NumFences`

[in] Number of native fences that the OS updates current values of.

### `Flags`

[in] A [**DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_updatecurrentvaluesfromcpu_flags) structure that contains the flags for the update.

### `Reserved[28]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_updatecurrentvaluesfromcpu_flags)

[**DxgkDdiUpdateCurrentValuesFromCpu**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatecurrentvaluesfromcpu)