## Description

The D3D runtime calls ***D3DKMTOpenNativeFenceFromNTHandle** to open an existing shared native fence on a different device or process.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_OPENNATIVEFENCEFROMNTHANDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_opennativefencefromnthandle) structure that describes the fence object to open.

## Return value

**D3DKMTOpenNativeFenceFromNTHandle** returns STATUS_SUCCESS on successful creation. Otherwise it returns an NTSTATUS error code such as STATUS_INVALID_PARAMETER.

## Remarks

If the native fence is being opened on a different device of the same process, then [**NativeFenceMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_opennativefencefromnthandle) contains the same virtual addresses as the original native fence. If it is being opened on a different process, then **NativeFenceMapping** contains new VAs mapped in the new process address space.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DKMT_OPENNATIVEFENCEFROMNTHANDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_opennativefencefromnthandle)

[**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence)

[**D3DKMTDestroySynchronizationObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroysynchronizationobject)

[**DxgkDdiOpenNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_opennativefence)