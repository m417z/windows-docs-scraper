# PFND3DKMT_ENUMADAPTERS2 callback function

## Description

The PFND3DKMT_ENUMADAPTERS2 callback function enumerates all graphics and display adapters on the system.

## Parameters

### `unnamedParam1`

*\_Inout\_* *[D3DKMT_ENUMADAPTERS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2)* * *Arg1*

Caller passes in array size and empty array space.
Callee verifies enough room in the array, fills out array, and passes back how much of the array was used.

## Return value

This function returns NTSTATUS.

Return Code | Description
--- | ---
STATUS_BUFFER_TOO_SMALL | When the provided array is too small to receive all the adapters.
STATUS_INVALID_PARAMETER | When pEnumAdapters is null or is otherwise an invalid memory region.
STATUS_NO_MEMORY | When memory cannot be allocated to satisfy the operation.

## Prototype

```cpp
//Declaration

PFND3DKMT_ENUMADAPTERS2 Pfnd3dkmtEnumadapters2;

// Definition

NTSTATUS Pfnd3dkmtEnumadapters2
(
	const D3DKMT_ENUMADAPTERS2 *
)
{...}

```

## Remarks

When D3DKMT_ENUMADAPTERS2\::pAdapters is null, D3DKMT_ENUMADAPTERS2\::NumAdapters is set to the maximum supported adapter count.
Callees will commonly invoke the method, first, to retrieve the maximum supported adapter count.

When the callee successfully enumerates adapters, it becomes responsible for explicitly managing the lifespan of adapter D3DKMT_HANDLEs.
These handles are returned to the callee through pEnumAdapters, and must be closed with [D3DKMTCloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter).

## See also

- [D3DKMT_ENUMADAPTERS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2)
- [D3DKMTEnumAdapters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters2)
- [PFND3DKMT_CLOSEADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_closeadapter)