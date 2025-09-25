# PFND3DKMT_GETMULTISAMPLEMETHODLIST callback function

## Description

Pfnd3dkmtGetmultisamplemethodlist retrieves a list of multiple-sample methods that are used for an allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getmultisamplemethodlist) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETMULTISAMPLEMETHODLIST Pfnd3dkmtGetmultisamplemethodlist;

// Definition

NTSTATUS Pfnd3dkmtGetmultisamplemethodlist
(
	D3DKMT_GETMULTISAMPLEMETHODLIST *
)
{...}

```

## Remarks

## See also