# IDXVAHD_Device::GetVideoProcessorCustomRates

## Description

Gets a list of custom rates that a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor supports. Custom rates are used for frame-rate conversion and inverse telecine (IVTC).

## Parameters

### `pVPGuid` [in]

A GUID that identifies the video processor to query. This GUID must equal the value of the **VPGuid** member from one of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structures retrieved by the [IDXVAHD_Device::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcaps) method.

### `Count` [in]

The number of rates to retrieve. This parameter must equal the **CustomRateCount** member of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structure for the video processor.

### `pRates` [out]

A pointer to an array of [DXVAHD_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_custom_rate_data) structures. The *Count* parameter specifies the number of elements in the array. The method fills the array with a list of custom rates.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device)