# PFND3DKMT_CREATECONTEXTVIRTUAL callback function

## Description

The D3dkmtCreateContextVirtual callback function creates a virtual context.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a [D3DKMT_CREATECONTEXTVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontextvirtual) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATECONTEXTVIRTUAL Pfnd3dkmtCreatecontextvirtual;

// Definition

NTSTATUS Pfnd3dkmtCreatecontextvirtual
(
	D3DKMT_CREATECONTEXTVIRTUAL *
)
{...}

```