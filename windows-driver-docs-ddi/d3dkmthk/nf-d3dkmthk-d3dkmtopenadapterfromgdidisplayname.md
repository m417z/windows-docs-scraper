# D3DKMTOpenAdapterFromGdiDisplayName function

## Description

The **D3DKMTOpenAdapterFromGdiDisplayName** function maps a GDI device name to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.

## Parameters

### `unnamedParam1`

*pData* [in, out]

 A pointer to a [D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromgdidisplayname) structure that describes the parameters that are required to perform the mapping.

## Return value

**D3DKMTOpenAdapterFromGdiDisplayName** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect or the Windows Vista display driver model was not used.|

This function might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A graphics adapter corresponds to a video card. A monitor output corresponds to a head on a video card. A system with a single video card contains only one adapter. However, if the video card supports multiple heads, it supports outputting to multiple monitors.

## See also

[D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openadapterfromgdidisplayname)