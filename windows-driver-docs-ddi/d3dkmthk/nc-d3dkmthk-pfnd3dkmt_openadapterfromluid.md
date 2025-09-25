# PFND3DKMT_OPENADAPTERFROMLUID callback function

## Description

Pfnd3dkmtOpenadapterfromluid maps a locally unique identifier (LUID) to a graphics adapter handle.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENADAPTERFROMLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromluid) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENADAPTERFROMLUID Pfnd3dkmtOpenadapterfromluid;

// Definition

NTSTATUS Pfnd3dkmtOpenadapterfromluid
(
	D3DKMT_OPENADAPTERFROMLUID *
)
{...}

```

## Remarks

## See also