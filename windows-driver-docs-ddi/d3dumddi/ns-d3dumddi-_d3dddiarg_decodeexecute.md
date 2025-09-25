# _D3DDDIARG_DECODEEXECUTE structure

## Description

The D3DDDIARG_DECODEEXECUTE structure describes a Microsoft DirectX Video Acceleration (VA) decode operation to perform.

## Members

### `hDecode` [in]

A handle to the DirectX VA decode device. The user-mode display driver returns this handle in a call to its [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

### `NumCompBuffers` [in]

The number of compressed buffer that are pointed to by the **pCompressedBuffers** member.

### `pCompressedBuffers` [in]

A pointer to a list of [DXVADDI_DECODEBUFFERDESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferdesc) structures that describe the compressed buffers that are passed from the host decoder to the accelerator.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[DXVADDI_DECODEBUFFERDESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferdesc)

[DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute)