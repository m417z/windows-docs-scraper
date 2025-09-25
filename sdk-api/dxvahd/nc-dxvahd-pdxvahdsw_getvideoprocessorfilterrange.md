# PDXVAHDSW_GetVideoProcessorFilterRange callback function

## Description

Gets the supported range of image filter values from a software plug-in Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `Filter` [in]

The type of image filter, specified as a member of the [DXVAHD_FILTER](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_filter) enumeration.

### `pRange` [out]

A pointer to a [DXVAHD_FILTER_RANGE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_filter_range_data) structure. The function fills the structure with the range of values for the specified filter.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::GetVideoProcessorFilterRange](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorfilterrange)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)