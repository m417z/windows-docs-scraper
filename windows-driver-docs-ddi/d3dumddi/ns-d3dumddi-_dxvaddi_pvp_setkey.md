# _DXVADDI_PVP_SETKEY structure

## Description

The DXVADDI_PVP_SETKEY structure describes a key that the decode device uses to start decoding a frame.

## Members

### `ContentKey` [in]

A [DXVADDI_PVP_KEY128](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_block128) structure that contains the 128-bit key.

## See also

[D3DDDIARG_DECODEBEGINFRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodebeginframe)

[DXVADDI_PVP_KEY128](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_block128)

[DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)