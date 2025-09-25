# PFND3DKMT_OPENADAPTERFROMDEVICENAME callback function

## Description

Pfnd3dkmtOpenadapterfromdevicename maps a device name to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENADAPTERFROMDEVICENAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromdevicename) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENADAPTERFROMDEVICENAME Pfnd3dkmtOpenadapterfromdevicename;

// Definition

NTSTATUS Pfnd3dkmtOpenadapterfromdevicename
(
	D3DKMT_OPENADAPTERFROMDEVICENAME *
)
{...}

```

## Remarks

## See also