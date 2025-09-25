# PFND3DDDI_DECODEENDFRAME callback function

## Description

The **DecodeEndFrame** function notifies the user-mode display driver that all of the data that was required to decode the current frame was submitted.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_DECODEENDFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeendframe) structure that describes the DirectX VA decoder that should stop decoding a frame.

## Return value

**DecodeEndFrame** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Decoding successfully completed.|
|E_OUTOFMEMORY|DecodeEndFrame could not allocate the required memory for it to complete.|

## Remarks

The **DecodeEndFrame** function notifies the user-mode display driver that its [DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute) function can no longer be called on the specified decode device.

## See also

[D3DDDIARG_DECODEENDFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeendframe)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute)