# D3DKMTQueryAdapterInfo function

## Description

The **D3DKMTQueryAdapterInfo** function retrieves adapter information from an adapter handle.

## Parameters

### `unnamedParam1` [in/out]

Pointer to a [**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo) structure that describes the adapter information to retrieve.

## Return value

**D3DKMTQueryAdapterInfo** returns an NTSTATUS code such as one of the following:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Adapter information was successfully retrieved. |
| STATUS_DEVICE_REMOVED | The adapter was stopped. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | **D3DKMTQueryAdapterInfo** couldn't complete because of insufficient memory. |

## See also

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**PFND3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_queryadapterinfo)