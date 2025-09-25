# ID3D11Device::CheckFeatureSupport

## Description

Gets information about the features that are supported by the current graphics driver.

## Parameters

### `Feature`

Type: **[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)**

A member of the [D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature) enumerated type that describes which feature to query for support.

### `pFeatureSupportData` [out]

Type: **void***

Upon completion of the method, the passed structure is filled with data that describes the feature support.

### `FeatureSupportDataSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the structure passed to the *pFeatureSupportData* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns E_INVALIDARG if an unsupported data type is passed to the *pFeatureSupportData* parameter
or a size mismatch is detected for the *FeatureSupportDataSize* parameter.

## Remarks

To query for multi-threading support, pass the **D3D11_FEATURE_THREADING** value to the *Feature* parameter, pass
the [D3D11_FEATURE_DATA_THREADING](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_threading) structure to the *pFeatureSupportData* parameter, and pass the size of
the **D3D11_FEATURE_DATA_THREADING** structure to the *FeatureSupportDataSize* parameter.

Calling CheckFeatureSupport with *Feature* set to D3D11_FEATURE_FORMAT_SUPPORT causes the method to return the same information that would be returned
by [ID3D11Device::CheckFormatSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkformatsupport).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)