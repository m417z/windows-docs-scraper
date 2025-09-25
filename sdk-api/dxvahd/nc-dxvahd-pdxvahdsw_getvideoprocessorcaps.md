# PDXVAHDSW_GetVideoProcessorCaps callback function

## Description

Gets the capabilities of one or more software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processors.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `pContentDesc` [in]

A pointer to a [DXVAHD_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_content_desc) structure that describes the video content.

### `Usage` [in]

A member of the [DXVAHD_DEVICE_USAGE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_usage) enumeration, describing how the video processor will be used.

### `Count` [in]

The number of elements in the *pCaps* array.

### `pCaps` [out]

A pointer to an array of [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structures. The function fills the structures with the capabilities of the plug-in video processors.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcaps)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)