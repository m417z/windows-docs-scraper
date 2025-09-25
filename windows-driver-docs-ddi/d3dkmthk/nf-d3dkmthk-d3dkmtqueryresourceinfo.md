# D3DKMTQueryResourceInfo function

## Description

The **D3DKMTQueryResourceInfo** function retrieves information about a shared resource.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_QUERYRESOURCEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryresourceinfo) structure that contains parameters for retrieving information about a shared resource.

## Return value

**D3DKMTQueryResourceInfo** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|Information about a shared resource was successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_INTEGER_OVERFLOW|The size of all of the private driver data was too big to return to the OpenGL ICD.|

This function might also return other NTSTATUS values.

## Remarks

The OpenGL ICD typically calls **D3DKMTQueryResourceInfo** to obtain information about the resource and then uses this information to allocate the appropriate buffers for a call to [D3DKMTOpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource).

For an example of how an OpenGL ICD can use **D3DKMTQueryResourceInfo** to retrieve information about a shared resource, see the code example in [D3DKMTOpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource).

## See also

[D3DKMTOpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource)

[D3DKMT_QUERYRESOURCEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryresourceinfo)