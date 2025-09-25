# PFND3DKMT_CREATEOUTPUTDUPL callback function

## Description

Reserved for system use. Do not use in your driver.

## Parameters

### `unnamedParam1`

Pointer to a D3DKMT_CREATE_OUTPUTDUPL structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATEOUTPUTDUPL Pfnd3dkmtCreateoutputdupl;

// Definition

NTSTATUS Pfnd3dkmtCreateoutputdupl
(
	const D3DKMT_CREATE_OUTPUTDUPL *
)
{...}

```