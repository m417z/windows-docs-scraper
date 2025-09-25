# D3DKMTCloseAdapter function

## Description

The **D3DKMTCloseAdapter** function closes an adapter that was previously opened by various functions.

## Parameters

### `unnamedParam1` [in]

Pointer to a [D3DKMT_CLOSEADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_closeadapter) structure that specifies the adapter to close.

## Return value

**D3DKMTCloseAdapter** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The adapter was closed successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect or the Windows Vista display driver model was not used. |

This function might also return other **NTSTATUS** values.

## See also

- [D3DKMT_CLOSEADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_closeadapter)
- [PFND3DKMT_CLOSEADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_closeadapter)
- [D3DKMTEnumAdapters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters2)