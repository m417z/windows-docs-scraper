## Description

**DXGKARG_OPENNATIVEFENCE** is the structure passed to [**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence).

## Members

### `hGlobalNativeFence`

[in] Driver-assigned handle to the fence object created in the prior call to [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence).

### `hLocalNativeFence`

[in/out] On input, the value of **hLocalNativeFence** is the *Dxgkrnl*-generated handle of the object.

On output, the value returned by the KMD is the internal, KMD-maintained handle to be used by subsequent callbacks to refer to this local fence object.

### `hDevice`

[in] Driver handle for the parent device of this local fence object.

### `CurrentValueGpuVa`

[in] Read/write mapping of the current value for the GPU in user process address space.

### `MonitoredValueGpuVa`

[in] Read/write mapping of the monitored value for the GPU in user process address space.

### `Flags`

[in] A [**DXGK_OPENNATIVEFENCE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_opennativefence_flags) structure containing flags that indicate how to open the local GPU fence object.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence)