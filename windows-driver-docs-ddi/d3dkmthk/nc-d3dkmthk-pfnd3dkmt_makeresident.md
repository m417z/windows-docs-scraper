# PFND3DKMT_MAKERESIDENT callback function

## Description

Pfnd3dkmtMakeresident adds a resource to the device residency list and increment the residency reference count on this allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_MAKERESIDENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_MAKERESIDENT Pfnd3dkmtMakeresident;

// Definition

NTSTATUS Pfnd3dkmtMakeresident
(
	D3DDDI_MAKERESIDENT *
)
{...}

```

## Remarks

## See also