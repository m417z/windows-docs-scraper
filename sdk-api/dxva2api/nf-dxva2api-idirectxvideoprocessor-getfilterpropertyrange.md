# IDirectXVideoProcessor::GetFilterPropertyRange

## Description

Retrieves the range of values for an image filter supported by this device.

## Parameters

### `FilterSetting` [in]

Filter setting to query. For more information, see [DXVA Image Filter Settings](https://learn.microsoft.com/windows/desktop/medfound/dxva-image-filter-settings).

### `pRange` [out]

Pointer to a [DXVA2_ValueRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_valuerange) structure that receives the range of values for the setting specified in *FilterSetting*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)