# D3DKMTOpenAdapterFromLuid function

## Description

Maps a locally unique identifier (LUID) to a graphics adapter handle.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [D3DKMT_OPENADAPTERFROMLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromluid) structure that describes information that is required to perform the mapping.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The mapping was performed successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other NTSTATUS values.

## See also

[D3DKMT_OPENADAPTERFROMLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromluid)