# PFND3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME callback function

## Description

The PFND3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME callback function opens an NT handle for a named shared monitored fence object, similar to what D3DKMTOpenNtHandleFromName does for shared allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectnthandlefromname) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME Pfnd3dkmtOpensyncobjectnthandlefromname;

// Definition

NTSTATUS Pfnd3dkmtOpensyncobjectnthandlefromname
(
	D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME *
)
{...}

```

## Remarks

## See also