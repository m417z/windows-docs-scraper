# ID2D1EffectContext::GetMaximumSupportedFeatureLevel

## Description

This indicates the maximum feature level from the provided list which is supported by the device. If none of the provided levels are supported, then this API fails with D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES.

## Parameters

### `featureLevels` [in]

Type: **const [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

The feature levels provided by the application.

### `featureLevelsCount`

Type: **UINT32**

The count of feature levels provided by the application

### `maximumSupportedFeatureLevel` [out]

Type: **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

The maximum feature level from the *featureLevels* list which is supported by the D2D device.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |
| D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES | None of the provided levels are supported. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)