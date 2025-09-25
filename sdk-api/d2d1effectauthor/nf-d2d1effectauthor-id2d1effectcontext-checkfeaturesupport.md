# ID2D1EffectContext::CheckFeatureSupport

## Description

This indicates whether an optional capability is supported by the D3D device.

## Parameters

### `feature`

Type: **[D2D1_FEATURE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_feature)**

The feature to query support for.

### `featureSupportData` [out]

Type: **void***

A structure indicating information about how or if the feature is supported.

### `featureSupportDataSize` [out]

Type: **UINT32**

The size of the *featureSupportData* parameter.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)