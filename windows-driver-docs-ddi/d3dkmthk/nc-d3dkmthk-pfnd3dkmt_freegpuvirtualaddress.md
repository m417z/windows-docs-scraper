# PFND3DKMT_FREEGPUVIRTUALADDRESS callback function

## Description

The Pfnd3dkmtFreegpuvirtualaddress callback function releases a range of graphics processing unit (GPU) virtual addresses, which was previously reserved or mapped.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_FREEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_freegpuvirtualaddress) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_FREEGPUVIRTUALADDRESS Pfnd3dkmtFreegpuvirtualaddress;

// Definition

NTSTATUS Pfnd3dkmtFreegpuvirtualaddress
(
	const D3DKMT_FREEGPUVIRTUALADDRESS *
)
{...}

```

## Remarks

## See also