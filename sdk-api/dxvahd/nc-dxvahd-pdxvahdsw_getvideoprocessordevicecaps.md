# PDXVAHDSW_GetVideoProcessorDeviceCaps callback function

## Description

Gets the capabilities of a software plug-in Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `pContentDesc` [in]

A pointer to a [DXVAHD_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_content_desc) structure that describes the video content.

### `Usage` [in]

A member of the [DXVAHD_DEVICE_USAGE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_usage) enumeration, describing how the device will be used. The value indicates the desired trade-off between speed and video quality.

### `pCaps` [out]

A pointer to a [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure that receives the device capabilities.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)