## Description

The OS calls KMD's **DxgkDdiCreateNativeFence** to create a tracking object for a native GPU fence.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCreateNativeFence`

[in/out] Pointer to a [**DXGKARG_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createnativefence) structure that describes the native GPU fence to create.

## Return value

**DxgkDdiCreateNativeFence** returns STATUS_SUCCESS if KMD was able to successfully create a native GPU fence object. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createnativefence)

[**DxgkDdiDestroyNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroynativefence)

[**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence)