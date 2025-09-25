# PFND3DKMT_INVALIDATECACHE callback function

## Description

Pfnd3dkmtInvalidatecache invalidates cache.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_INVALIDATECACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidatecache) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_INVALIDATECACHE Pfnd3dkmtInvalidatecache;

// Definition

NTSTATUS Pfnd3dkmtInvalidatecache
(
	const D3DKMT_INVALIDATECACHE *
)
{...}

```

## Remarks

## See also