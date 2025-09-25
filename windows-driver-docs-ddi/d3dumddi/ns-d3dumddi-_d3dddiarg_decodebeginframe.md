# _D3DDDIARG_DECODEBEGINFRAME structure

## Description

The D3DDDIARG_DECODEBEGINFRAME structure specifies the Microsoft DirectX Video Accelerator (VA) decoder that should start decoding a frame.

## Members

### `hDecode`

A handle to the DirectX VA decode device. The user-mode display driver returns this handle in a call to its [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

### `pPVPSetKey`

A pointer to the [DXVADDI_PVP_SETKEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_setkey) structure that contains a key that the driver requires for the decode device to start operating.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[DXVADDI_PVP_SETKEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_setkey)

[DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)