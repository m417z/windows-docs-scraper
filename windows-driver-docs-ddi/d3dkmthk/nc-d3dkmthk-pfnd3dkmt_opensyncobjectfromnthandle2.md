# PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 callback function

## Description

The PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 callback function maps an NT process handle to a graphics processing unit (GPU) synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 Pfnd3dkmtOpensyncobjectfromnthandle2;

// Definition

NTSTATUS Pfnd3dkmtOpensyncobjectfromnthandle2
(
	D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 *
)
{...}

```

## Remarks

## See also