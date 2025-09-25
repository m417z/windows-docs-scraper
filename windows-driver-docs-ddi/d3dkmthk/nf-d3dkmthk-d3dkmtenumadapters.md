# D3DKMTEnumAdapters function

## Description

Enumerates all graphics adapters on the system.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [D3DKMT_ENUMADAPTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters) structure that lists all graphics adapters and their characteristics.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The enumeration was successful. |
| STATUS_INVALID_PARAMETER | The pEnumAdapters parameter was validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The operating system enumerates graphics adapters in the same sequence as their corresponding physical devices.

## See also

[D3DKMT_ENUMADAPTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters)