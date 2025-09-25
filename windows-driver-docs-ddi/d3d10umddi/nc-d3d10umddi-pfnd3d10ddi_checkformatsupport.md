# PFND3D10DDI_CHECKFORMATSUPPORT callback function

## Description

Retrieves the capabilities that the device has with the specified format.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*Format* [in]

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) typed value that indicates the pixel format to retrieve capabilities for.

### `unnamedParam3`

*pFormatCaps* [out]

A pointer to a variable that receives a valid bitwise **OR** of the following values that indicate the capabilities.

| Value | Description |
| ----- | ----------- |
| D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE (0x00000001) | The format can be sampled with any filter in shaders.|
| D3D10_DDI_FORMAT_SUPPORT_RENDERTARGET (0x00000002) | The format can be a render target.|
| D3D10_DDI_FORMAT_SUPPORT_BLENDABLE (0x00000004) | The format is blendable. (You can set this value only if the format can be a render target.) |
| D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET (0x00000008) | The format can be a render target with a sample count that is greater than one.|
| D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_LOAD (0x00000010) | The format can be used for reading individual samples from multiple-sample resources.|
| D3D10_DDI_FORMAT_SUPPORT_NOT_SUPPORTED (0x80000000) | The display device does not support the format at all. See Remarks. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_DECODER_OUTPUT (0x00000020) | The format can be supported as a decode output resource. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_VIDEO_PROCESSOR_OUTPUT (0x00000040) | The format can be a video processor output resource. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_VIDEO_PROCESSOR_INPUT (0x00000080) | The format can be a video processor input resource. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_VERTEX_BUFFER (0x00000100) | The format can be a vertex buffer. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_UAV_WRITES (0x00000200) | The format can be written through an unordered access view (UAV) append buffer. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_BUFFER (0x00000400) | The format can be used in a typed Buffer view. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_CAPTURE (0x00000800) | The format can be supported as an output to the video capture engine. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_VIDEO_ENCODER (0x00001000) | The format can be supported as an input to a hardware-encode Media Foundation Transform (MFT). Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_OUTPUT_MERGER_LOGIC_OP (0x00002000) | The format supports shader logic operations. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_SHADER_GATHER (0x00004000) | The format supports "Shader gather4" resource attributes. Available starting with Windows 8.|
| D3D11_1DDI_FORMAT_SUPPORT_MULTIPLANE_OVERLAY (0x00008000) | The format supports multiplane overlays. Available starting with Windows 8. However, multiplane overlays are supported only in WDDM 1.3 and later drivers, which were introduced with Windows 8.1.|
| D3DWDDM1_3DDI_FORMAT_SUPPORT_TILED (0x00010000) | The format supports use in a tiled resource of type D3D10DDIRESOURCE_TEXTURE1D, D3D10DDIRESOURCE_TEXTURE2D, or D3D10DDIRESOURCE_TEXTURECUBE. Available starting with Windows 8.1, and supported only by WDDM 1.3 and later drivers.|

## Remarks

 The D3D10_DDI_FORMAT_SUPPORT_NOT_SUPPORTED value is valid only for the following formats:

* DXGI_FORMAT_A8P8
* DXGI_FORMAT_AI44
* DXGI_FORMAT_AYUV
* DXGI_FORMAT_IA44
* DXGI_FORMAT_NV11
* DXGI_FORMAT_P010
* DXGI_FORMAT_P016
* DXGI_FORMAT_P8
* DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
* DXGI_FORMAT_Y210
* DXGI_FORMAT_Y216
* DXGI_FORMAT_Y410
* DXGI_FORMAT_Y416

For these formats, only this bit should be set.

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code as follows:

* Set to E_FAIL if the format in the **Format** parameter does not exist.
* Set to E_INVALIDARG if the **pFormatCaps** parameter is NULL.

## See also

[**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)

[**DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM**](https://learn.microsoft.com/windows-hardware/drivers/display/dxgi-format-r10g10b10-xr-bias-a2-unorm)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)