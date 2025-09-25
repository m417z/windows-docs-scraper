## Description

**D3DDDI_NATIVEFENCEINFO** describes the attributes of a native fence synchronization object.

## Members

### `InitialFenceValue`

[in] The initial fence value.

### `EngineAffinity`

[in] Defines the physical adapters where the GPU virtual address is mapped.

### `Type`

[in] A [**D3DDDI_NATIVEFENCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type) value that specifies the type of the fence.

### `Flags`

[in] A [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) structure that identifies the attributes of the synchronization object.

### `NativeFenceMapping`

[out] A [**D3DDDI_NATIVEFENCE_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_nativefencemapping) structure in which the process mapping information for the native fence is returned.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DKMT_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_createnativefence)

[**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence)