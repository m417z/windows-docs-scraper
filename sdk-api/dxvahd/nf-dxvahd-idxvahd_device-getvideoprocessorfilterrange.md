# IDXVAHD_Device::GetVideoProcessorFilterRange

## Description

Gets the range of values for an image filter that the Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device supports.

## Parameters

### `Filter` [in]

The type of image filter, specified as a member of the [DXVAHD_FILTER](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_filter) enumeration.

### `pRange` [out]

A pointer to a [DXVAHD_FILTER_RANGE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_filter_range_data) structure. The method fills the structure with the range of values for the specified filter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *Filter* parameter is invalid or the device does not support the specified filter. |

## Remarks

To find out which image filters the device supports, check the **FilterCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. Call the [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) method to get this value.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device)