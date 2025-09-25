# PFND3DKMT_OPENRESOURCE callback function

## Description

Pfnd3dkmtOpenresource opens a shared resource.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresource) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENRESOURCE Pfnd3dkmtOpenresource;

// Definition

NTSTATUS Pfnd3dkmtOpenresource
(
	D3DKMT_OPENRESOURCE *
)
{...}

```

## Remarks

## See also