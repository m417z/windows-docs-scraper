# PFND3DKMT_RESERVEGPUVIRTUALADDRESS callback function

## Description

The PFND3DKMT_RESERVEGPUVIRTUALADDRESS callback function reserves an address range in the current process graphics processing unit (GPU) virtual address space.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_RESERVEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_reservegpuvirtualaddress) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_RESERVEGPUVIRTUALADDRESS Pfnd3dkmtReservegpuvirtualaddress;

// Definition

NTSTATUS Pfnd3dkmtReservegpuvirtualaddress
(
	D3DDDI_RESERVEGPUVIRTUALADDRESS *
)
{...}

```

## Remarks

## See also