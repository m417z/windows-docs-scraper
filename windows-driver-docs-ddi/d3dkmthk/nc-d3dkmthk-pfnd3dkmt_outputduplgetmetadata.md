# PFND3DKMT_OUTPUTDUPLGETMETADATA callback function

## Description

The PFND3DKMT_OUTPUTDUPLGETMETADATA callback function gets output duplicate metadata.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OUTPUTDUPL_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputdupl_metadata) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OUTPUTDUPLGETMETADATA Pfnd3dkmtOutputduplgetmetadata;

// Definition

NTSTATUS Pfnd3dkmtOutputduplgetmetadata
(
	D3DKMT_OUTPUTDUPL_METADATA *
)
{...}

```

## Remarks

## See also