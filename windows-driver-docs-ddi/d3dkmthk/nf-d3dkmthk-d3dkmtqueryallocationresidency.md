# D3DKMTQueryAllocationResidency function

## Description

The **D3DKMTQueryAllocationResidency** function retrieves the residency status of a resource or list of allocations.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_QUERYALLOCATIONRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryallocationresidency) structure that contains information for retrieving the residency status of a resource or list of allocations.

## Return value

**D3DKMTQueryAllocationResidency** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Residency status for allocations was successfully retrieved. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_QUERYALLOCATIONRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryallocationresidency)