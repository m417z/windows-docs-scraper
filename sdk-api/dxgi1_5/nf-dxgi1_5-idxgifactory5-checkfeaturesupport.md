# IDXGIFactory5::CheckFeatureSupport

## Description

Used to check for hardware feature support.

## Parameters

### `Feature`

Type: **[DXGI_FEATURE](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_feature)**

Specifies one member of [DXGI_FEATURE](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_feature) to query support for.

### `pFeatureSupportData` [in, out]

Type: **void***

Specifies a pointer to a buffer that will be filled with data that describes the feature support.

### `FeatureSupportDataSize`

Type: **UINT**

The size, in bytes, of *pFeatureSupportData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

Refer to the description of [DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag).

## See also

[IDXGIFactory5](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nn-dxgi1_5-idxgifactory5)