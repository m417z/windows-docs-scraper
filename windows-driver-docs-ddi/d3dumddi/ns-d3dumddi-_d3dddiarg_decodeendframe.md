# _D3DDDIARG_DECODEENDFRAME structure

## Description

The D3DDDIARG_DECODEENDFRAME structure specifies the Microsoft DirectX Video Accelerator (VA) decoder that should stop decoding a frame.

## Members

### `hDecode`

A handle to the DirectX VA decode device. The user-mode display driver returns this handle in a call to its [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

### `pHandleComplete`

This member is reserved and should be set to **NULL**.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe)