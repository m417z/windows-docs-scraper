# PFND3DKMT_OPENADAPTERFROMGDIDISPLAYNAME callback function

## Description

Pfnd3dkmtOpenadapterfromgdidisplayname maps a GDI device name to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromgdidisplayname) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENADAPTERFROMGDIDISPLAYNAME Pfnd3dkmtOpenadapterfromgdidisplayname;

// Definition

NTSTATUS Pfnd3dkmtOpenadapterfromgdidisplayname
(
	D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME *
)
{...}

```

## Remarks

## See also