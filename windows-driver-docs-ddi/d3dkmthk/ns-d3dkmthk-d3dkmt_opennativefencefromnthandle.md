## Description

The **D3DKMT_OPENNATIVEFENCEFROMNTHANDLE** structure is a parameter for the [**D3DKMTOpenNativeFenceFromNTHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennativefencefromnthandle) function. It describes the native fence to open.

## Members

### `hNtHandle`

[in] NT handle for the shared fence object.

### `hDevice`

[in] Device handle to open this fence object on.

### `EngineAffinity`

[in] Defines the physical adapters where the GPU virtual address is mapped.

### `Flags`

[in] A [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) structure that identifies the attributes of the synchronization object.

### `hSyncObject`

[out] Handle to the opened fence object.

### `NativeFenceMapping`

[out] A [**D3DDDI_NATIVEFENCEMAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_nativefencemapping) structure that contains process mapping information for the fence object.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DKMTOpenNativeFenceFromNTHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennativefencefromnthandle)