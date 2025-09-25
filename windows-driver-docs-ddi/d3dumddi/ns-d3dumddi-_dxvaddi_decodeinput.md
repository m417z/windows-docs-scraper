# _DXVADDI_DECODEINPUT structure

## Description

The DXVADDI_DECODEINPUT structure describes a render target format that is supported by a Microsoft DirectX Video Acceleration (DirectX VA) decode type.

## Members

### `pGuid` [in]

A pointer to the GUID that represents the DirectX VA decode type.

### `VideoDesc` [in]

A [DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure for the render target that is supported by the decode type that **pGuid** points to.

## Remarks

A pointer to the DXVADDI_DECODEINPUT structure is specified in the **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure--along with a D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFO value in the **Type** member of D3DDDIARG_GETCAPS--in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to retrieve information about the types of compressed buffers that are required to decode video. The compressed buffer information is returned in a pointer to a [DXVADDI_DECODEBUFFERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferinfo) structure through the **pData** member of D3DDDIARG_GETCAPS.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXVADDI_DECODEBUFFERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferinfo)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)