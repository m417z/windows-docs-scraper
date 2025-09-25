# PFND3DKMT_EVICT callback function

## Description

The Pfnd3dkmtEvict instructs the OS to decrement the residency reference count.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_evict) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_EVICT Pfnd3dkmtEvict;

// Definition

NTSTATUS Pfnd3dkmtEvict
(
	D3DKMT_EVICT *
)
{...}

```

## Remarks

## See also