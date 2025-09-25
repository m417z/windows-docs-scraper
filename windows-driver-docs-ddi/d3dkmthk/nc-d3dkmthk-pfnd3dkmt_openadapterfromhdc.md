# PFND3DKMT_OPENADAPTERFROMHDC callback function

## Description

Pfnd3dkmtOpenadapterfromhdc maps a device context handle (HDC) to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENADAPTERFROMHDC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromhdc) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENADAPTERFROMHDC Pfnd3dkmtOpenadapterfromhdc;

// Definition

NTSTATUS Pfnd3dkmtOpenadapterfromhdc
(
	D3DKMT_OPENADAPTERFROMHDC *
)
{...}

```

## Remarks

## See also