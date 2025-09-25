## Description

Gets information about the features that are supported by the current video driver.

## Parameters

### `Feature`

A member of the [D3D11_FEATURE_VIDEO](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_feature_video) enumeration that specifies the feature to query for support.

### `pFeatureSupportData`

A structure that contains data that describes the configuration details of the feature for which support is requested and, upon the completion of the call, is populated with details about the level of support available. For information on the structure that is associated with each type of feature support request, see the field descriptions for [D3D11_FEATURE_VIDEO](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_feature_video).

### `FeatureSupportDataSize`

The size of the structure passed to the *pFeatureSupportData* parameter.

## Return value

Returns **S_OK** if successful; otherwise, returns **E_INVALIDARG** if an unsupported data type is passed to the *pFeatureSupportData* parameter or a size mismatch is detected for the *FeatureSupportDataSize* parameter.

## Remarks

## See also

[D3D11_FEATURE_VIDEO](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_feature_video)