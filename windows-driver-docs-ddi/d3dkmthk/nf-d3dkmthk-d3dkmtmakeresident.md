# D3DKMTMakeResident function

## Description

**D3DKMTMakeResident** is used to add a resource to the device residency list and increment the residency reference count on this allocation.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DDDI_MAKERESIDENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DDDI_MAKERESIDENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident)