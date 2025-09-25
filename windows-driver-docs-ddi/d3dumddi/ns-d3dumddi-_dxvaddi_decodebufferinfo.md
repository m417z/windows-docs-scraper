# _DXVADDI_DECODEBUFFERINFO structure

## Description

The DXVADDI_DECODEBUFFERINFO structure describes information about a particular type of compressed buffer that is required for a video decoding scenario.

## Members

### `CompressedBufferType` [out]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the buffer.

### `CreationWidth` [out]

The width of the data in the buffer as the number of units of bits. For example, AYUV data is specified in 32-bit units, IA44/AI44 data is specified in 8-bit units, and DPXD data is specified in 2-bit units.

The driver must assign a value to **CreationWidth** that is a multiple of 2 and does not exceed 65535.

### `CreationHeight` [out]

The height of the data in the buffer as the number of units of bits. For example, AYUV data is specified in 32-bit units, IA44/AI44 data is specified in 8-bit units, and DPXD data is specified in 2-bit units.

The driver must assign a value to **CreationHeight** that does not exceed 65535.

### `CreationPool` [out]

A [D3DDDI_POOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_pool)-typed value that indicates the type of memory that the buffer exists in.

## Remarks

A pointer to the [DXVADDI_DECODEINPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput) structure is specified in the **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure--along with a D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFO value in the **Type** member of D3DDDIARG_GETCAPS--in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to retrieve information about the types of compressed buffers that are required to accelerate a particular DirectX VA video decode type. The information about the types of compressed buffers is returned in an array of DXVADDI_DECODEBUFFERINFO structures through the **pData** member of D3DDDIARG_GETCAPS.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[DXVADDI_DECODEINPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodeinput)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)