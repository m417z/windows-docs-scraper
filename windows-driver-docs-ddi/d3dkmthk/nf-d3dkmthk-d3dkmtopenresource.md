# D3DKMTOpenResource function

## Description

The **D3DKMTOpenResource** function opens a shared resource.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresource) structure that contains parameters for opening a shared resource.

## Return value

**D3DKMTOpenResource** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The resource was successfully opened.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) values.

## See also

[D3DKMTQueryResourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfo)

[D3DKMT_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresource)