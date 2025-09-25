# PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE callback function

## Description

The PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE callback function maps an NT process handle to a graphics processing unit (GPU) synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENSYNCOBJECTFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENSYNCOBJECTFROMNTHANDLE Pfnd3dkmtOpensyncobjectfromnthandle;

// Definition

NTSTATUS Pfnd3dkmtOpensyncobjectfromnthandle
(
	D3DKMT_OPENSYNCOBJECTFROMNTHANDLE *
)
{...}

```

## Remarks

## See also