## Description

**DxgkDdiOpenNativeFence** is called by the OS to open a native GPU fence object.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pOpenNativeFence`

[in/out] Pointer to a [**DXGKARG_OPENNATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_opennativefence) structure that describes the native GPU fence to open.

## Return value

**DxgkDdiOpenNativeFence** returns STATUS_SUCCESS if KMD was able to successfully open a native GPU fence object. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

 **DxgkDdiOpenNativeFence** is always preceded by a call to [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence).

If a second process opens the shared native fence object using [**D3DKMT_OPENNATIVEFENCEFROMNTHANDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennativefencefromnthandle), *Dxgkrnl* does the following:

* Locates the **hGlobalNativeFence**.
* Creates a new CPU virtual address (VA) and GPU VA mapping for that existing object in the second process's address space.

*Dxgkrnl* passes this payload to the KMD by calling **DxgkDdiOpenNativeFence** along with a new [**hLocalNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_opennativefence) handle.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_OPENNATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_opennativefence)

[**DxgkDdiCloseNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_closenativefence)

[**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence)