# PDXVAHDSW_GetVideoProcessorCustomRates callback function

## Description

Gets the custom rates that a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor supports.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device.

### `pVPGuid` [in]

A GUID that identifies the video processor to query.

### `Count` [in]

The number of rates to retrieve.

### `pRates` [out]

A pointer to an array of [DXVAHD_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_custom_rate_data) structures. The *Count* parameter specifies the number of elements in the array. The function fills the array with a list of custom rates.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::GetVideoProcessorCustomRates](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcustomrates)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)