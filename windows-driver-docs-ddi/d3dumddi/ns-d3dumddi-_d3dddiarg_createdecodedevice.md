# D3DDDIARG_CREATEDECODEDEVICE structure

## Description

The **D3DDDIARG_CREATEDECODEDEVICE** structure describes a DirectX Video Acceleration (DXVA) decode device to create.

## Members

### `pGuid` [in]

A pointer to the GUID that represents the DXVA decode type. The Direct3D runtime calls the [**GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to query for the supported GUIDs.

### `VideoDesc` [in]

The [**DXVADDI_VIDEODESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure for the video stream that the decode device should decode.

### `pConfig` [in]

A pointer to the [**DXVADDI_CONFIGPICTUREDECODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_configpicturedecode) structure that contains the DirectX VA connection configuration data for compressed picture decoding that the decode device requires. The Direct3D runtime calls the [**GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to query for the supported configurations.

### `hDecode` [in/out]

A handle to the decode device. The user-mode display driver generates this handle for the Direct3D runtime to use to identify the decode device in subsequent calls.

## See also

[**CreateDecodeDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)
[**DXVADDI_CONFIGPICTUREDECODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_configpicturedecode)
[**DXVADDI_VIDEODESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)
[**GetCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)