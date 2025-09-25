# PDXVAHDSW_GetVideoProcessorOutputFormats callback function

## Description

Gets the output formats that are supported by a software plug-in Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `pContentDesc` [in]

A pointer to a [DXVAHD_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_content_desc) structure that describes the video content.

### `Usage` [in]

A member of the [DXVAHD_DEVICE_USAGE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_usage) enumeration, describing how the device will be used.

### `Count` [in]

The number of formats to retrieve.

### `pFormats` [out]

A pointer to an array of **D3DFORMAT** values. The *Count* parameter specifies the number of elements in the array. The function fills the array with a list of output formats.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::GetVideoProcessorOutputFormats](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessoroutputformats)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)