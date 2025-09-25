# PFND3DKMT_QUERYADAPTERINFO callback function

## Description

The **PFND3DKMT_QUERYADAPTERINFO** callback function retrieves adapter information from an adapter handle.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo) structure in which the adapter information is retrieved.

## Return value

**Pfnd3dkmtQueryadapterinfo** returns an NTSTATUS code such as one of the following:

| Return Code | Description |
| --- | --- |
| STATUS_SUCCESS | Adapter information was successfully retrieved. |
| STATUS_DEVICE_REMOVED | The adapter was stopped. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | Not enough memory could be allocated to satisfy the operation. |

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYADAPTERINFO Pfnd3dkmtQueryadapterinfo;

// Definition

NTSTATUS Pfnd3dkmtQueryadapterinfo
(
    const D3DKMT_QUERYADAPTERINFO *
)
{...}

```

## Remarks

## See also

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)