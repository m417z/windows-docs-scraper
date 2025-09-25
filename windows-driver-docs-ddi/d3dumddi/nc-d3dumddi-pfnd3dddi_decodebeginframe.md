# PFND3DDDI_DECODEBEGINFRAME callback function

## Description

The **DecodeBeginFrame** function notifies the user-mode display driver that decoding can begin on the specified Microsoft DirectX Video Accelerator (VA) decode device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DECODEBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodebeginframe) structure that describes information for the DirectX VA decoder to start decoding a frame.

## Return value

**DecodeBeginFrame** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | Decoding successfully began. |
| **E_OUTOFMEMORY** | [DecodeBeginFrame]() could not allocate the required memory for it to complete. |

## Remarks

The **DecodeBeginFrame** function notifies the user-mode display driver that its [DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute) function can be called on the specified decode device.

## See also

[D3DDDIARG_DECODEBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodebeginframe)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute)