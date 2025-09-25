# PFND3DDDI_DECODEEXECUTE callback function

## Description

The **DecodeExecute** function performs a decode operation by using the given Microsoft DirectX Video Accelerator (VA) decode device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DECODEEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeexecute) structure that describes the DirectX VA decode operation to perform.

## Return value

**DecodeExecute** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The DirectX VA decode operation is successfully performed.|
|E_OUTOFMEMORY|DecodeExecute could not allocate the required memory for it to complete.|

## Remarks

The Microsoft Direct3D runtime calls the **DecodeExecute** function for all of the standard DirectX VA decode operations. When **DecodeExecute** is first called for each frame, the [D3DDDIARG_DECODEEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeexecute) structure that is specified by **pData** should contain all of the buffer information that is required for decoding the frame. **DecodeExecute** can subsequently be called for the same frame; however, these calls require only incremental data. If the GUID for the particular DirectX VA decode type does not use a buffer that is specified in D3DDDIARG_DECODEEXECUTE, the handle and description for the buffer are set to **NULL**. For example, because the MPEG2 decode type requires picture parameters, a macroblock buffer, and a residual-difference buffer, all of these items must be present in the first call for each frame. Depending on the size of the data, however, the Direct3D runtime might call **DecodeExecute** again to supply only additional residual-difference data that is required to decode the entire frame.

DirectX VA 1.0 supported an external synchronization mechanism through a call to the [DdMoCompQueryStatus](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_mocompcb_querystatus) function. In DirectX VA 2.0, the user-mode display driver should perform its own synchronization, similar to the way it synchronizes the 3-D pipe. For more information about this synchronization, see [Synchronizing Video Decode Operations](https://learn.microsoft.com/windows-hardware/drivers/display/synchronizing-video-decode-operations).

## See also

[D3DDDIARG_DECODEEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeexecute)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)