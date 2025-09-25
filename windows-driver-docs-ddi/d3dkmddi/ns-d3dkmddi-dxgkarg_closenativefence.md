## Description

**DXGKARG_CLOSENATIVEFENCE** is the structure passed to [**DxgkDdiCloseNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_closenativefence).

## Members

### `hLocalNativeFence`

[in] Driver-assigned handle to the fence object opened in a prior call to [**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence).

### `Flags`

[in] A [**DXGK_CLOSENATIVEFENCE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_closenativefence_flags) structure containing flags that indicate how to close the local GPU fence object.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiCloseNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_closenativefence)

[**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence)