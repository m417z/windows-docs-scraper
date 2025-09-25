# PFND3DKMT_OPENRESOURCE2 callback function

## Description

Pfnd3dkmtOpenresource2 opens a shared resource.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresource) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENRESOURCE2 Pfnd3dkmtOpenresource2;

// Definition

NTSTATUS Pfnd3dkmtOpenresource2
(
	D3DKMT_OPENRESOURCE *
)
{...}

```

## Remarks

## See also