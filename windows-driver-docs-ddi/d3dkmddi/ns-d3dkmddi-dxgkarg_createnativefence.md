## Description

**DXGKARG_CREATENATIVEFENCE** is the structure passed to [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence) to describe a native GPU fence.

## Members

### `hGlobalNativeFence`

[in/out] On input, the value of **hGlobalNativeFence** is the *Dxgkrnl*-generated handle of the object.

On output, the value returned by the KMD is the internal, KMD-maintained handle to be used by subsequent callbacks to refer to this native GPU fence object.

### `Type`

[in] A [**D3DDDI_NATIVEFENCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type) value that indicates the type of native GPU fence object to create.

### `CurrentValueSystemProcessGpuVa`

[in] Read/write mapping of the current value for the GPU in system process address space. The OS has does this mapping only if KMD has set the [**DXGK_NATIVE_FENCE_CAPS::MapToGpuSystemProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_native_fence_caps) cap to TRUE.

### `MonitoredValueSystemProcessGpuVa`

[in] Read/write mapping of the monitored value for the GPU in system process address space. The OS has does this mapping only if KMD has set the [**DXGK_NATIVE_FENCE_CAPS::MapToGpuSystemProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_native_fence_caps) cap to TRUE.

### `pPrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE]`

[in/out] Pointer to the private driver data from the user-mode **CreateNativeFence** call, copied back to UMD.

### `Flags`

[in] A [**DXGKARG_CREATENATIVEFENCE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createnativefence_flags) structure containing flags to use when creating the native GPU fence object.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence)