# PFND3DKMT_ENUMADAPTERS3 callback function

## Description

The **PFND3DKMT_ENUMADAPTERS3** callback function enumerates graphics and display adapters on the system.

## Parameters

### `unnamedParam1` [in/out]

A [D3DKMT_ENUMADAPTERS3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters3) structure. The caller passes in the array size and an empty array space. The callee verifies that there is enough room in the array, fills out the array, and passes back how much of the array was used.

## Return value

This function returns NTSTATUS.

Return Code | Description
--- | ---
STATUS_BUFFER_TOO_SMALL | The provided array is too small to receive all the adapters.
STATUS_INVALID_PARAMETER | The pEnumAdapters member is null or is otherwise an invalid memory region.
STATUS_NO_MEMORY | Memory cannot be allocated to satisfy the operation.

## Prototype

```cpp
//Declaration

PFND3DKMT_ENUMADAPTERS3 Pfnd3dkmtEnumadapters3;

// Definition

NTSTATUS Pfnd3dkmtEnumadapters3
(
	const D3DKMT_ENUMADAPTERS3 *Arg1
)
{...}

```

## Remarks

When D3DKMT_ENUMADAPTERS3::pAdapters is null, D3DKMT_ENUMADAPTERS3::NumAdapters is set to the maximum supported adapter count. Callees will commonly invoke the method, first, to retrieve the maximum supported adapter count.

When the callee successfully enumerates adapters, it becomes responsible for explicitly managing the lifespan of adapter D3DKMT_HANDLEs. These handles are returned to the callee through **pEnumAdapters**, and must be closed with [**D3DKMTCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter).

Setting none of the D3DKMT_ENUMADAPTERS3::Filter flags will still enumerate adapters, but there are fewer adapters than [**PFND3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_enumadapters2) enumerates. ComputeOnly adapters are left out of the default enumeration, to avoid breaking applications. DisplayOnly adapters are also left out of the default enumeration.

## See also

[**D3DKMT_ENUMADAPTERS3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters3)

[**D3DKMTCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter)

[**D3DKMTEnumAdapters3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters3)

[**PFND3DKMT_CLOSEADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_closeadapter)

[**PFND3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_enumadapters2)