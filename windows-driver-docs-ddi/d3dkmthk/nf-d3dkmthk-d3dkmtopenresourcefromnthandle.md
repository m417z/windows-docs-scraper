# D3DKMTOpenResourceFromNtHandle function

## Description

Opens a shared resource from an NT handle.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENRESOURCEFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresourcefromnthandle) structure that describes information required to open a shared resource.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function completed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## Remarks

The NT handle to the process, which is used as the **hNtHandle** member of the [D3DKMT_OPENRESOURCEFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresourcefromnthandle) structure, is typically acquired by calling the [D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) or [D3DKMTOpenNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennthandlefromname) functions.

## See also

[D3DKMTOpenNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennthandlefromname)

[D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects)

[D3DKMT_OPENRESOURCEFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openresourcefromnthandle)