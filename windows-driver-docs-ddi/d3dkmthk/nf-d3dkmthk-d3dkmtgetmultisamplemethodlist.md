# D3DKMTGetMultisampleMethodList function

## Description

The **D3DKMTGetMultisampleMethodList** function retrieves a list of multiple-sample methods that are used for an allocation.

## Parameters

### `unnamedParam1` [in, out]

*pData*

A pointer to a [D3DKMT_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getmultisamplemethodlist) structure that describes the list of multiple-sample methods for an allocation.

## Return value

**D3DKMTGetMultisampleMethodList** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The list of multiple-sample methods was successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMT_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getmultisamplemethodlist)