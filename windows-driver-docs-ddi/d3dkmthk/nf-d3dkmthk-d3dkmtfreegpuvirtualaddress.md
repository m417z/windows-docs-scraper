# D3DKMTFreeGpuVirtualAddress function

## Description

**D3DKMTFreeGpuVirtualAddress** releases a range of graphics processing unit (GPU) virtual addresses, which was previously reserved or mapped.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_FREEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_freegpuvirtualaddress) structure that describes the operation.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was successfully created. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The freed virtual address should not be accessed immediately after the call. If there are outstanding [MapGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmapgpuvirtualaddress) and [UpdateGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdategpuvirtualaddress) operations, which reference the virtual address, they will be ignored after the virtual address is freed. A new virtual address range can be allocated in place of the freed one immediately after return from the function.

## See also

[D3DKMT_FREEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_freegpuvirtualaddress)

[MapGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmapgpuvirtualaddress)

[UpdateGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdategpuvirtualaddress)