## Description

**DXGKARG_DESTROYNATIVEFENCE** is the structure passed to [**DxgkDdiDestroyNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroynativefence).

## Members

### `hGlobalNativeFence`

[in] Handle to the global native GPU fence object. KMD returned this handle from a prior call to [**DXGKARG_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createnativefence).

### `Flags`

[in] A [**DXGKARG_DESTROYNATIVEFENCE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_destroynativefence_flags) structure containing flags to use when destroying the native GPU fence object.

### `Reserved[32]`

Reserved for system use.

## Remarks

KMD should destroy its global fence data associated with **hGlobalNativeFence**.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiDestroyNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroynativefence)