## Description

The **D3DKMT_CREATENATIVEFENCE** structure is a parameter for the [**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence) function. It describes the fence object to create.

## Members

### `hDevice`

[in] A handle to the device that the fence object is created on.

### `hSyncObject`

[out] A handle to the sync object on this process.

### `PrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE]`

[in/out] Private driver data to pass to KMD's [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence) function and copy back to UMD.

### `Info`

[in/out] A [**D3DDDI_NATIVEFENCEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_nativefenceinfo) structure that describes the attributes of the synchronization object.

### `Flags`

[in] A [**D3DKMT_CREATENATIVEFENCE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_createnativefence_flags) structure that describes the flags for the fence object.

### `Reserved[28]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence)

[**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence)