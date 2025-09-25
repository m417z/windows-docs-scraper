# ID3D12Device::CheckFeatureSupport

## Description

Gets information about the features that are supported by the current graphics driver.

## Parameters

### `Feature`

Type: **[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)**

A constant from the [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) enumeration describing the feature(s) that you want to query for support.

### `pFeatureSupportData` [in, out]

Type: **void***

A pointer to a data structure that corresponds to the value of the *Feature* parameter. To determine the corresponding data structure for each constant, see [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

### `FeatureSupportDataSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the structure pointed to by the *pFeatureSupportData* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful. Returns **E_INVALIDARG** if an unsupported data type is passed to the *pFeatureSupportData* parameter or if a size mismatch is detected for the *FeatureSupportDataSize* parameter.

## Remarks

As a usage example, to check for ray tracing support, specify the [D3D12_FEATURE_DATA_D3D12_OPTIONS5](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options5) structure in the *pFeatureSupportData* parameter. When the function completes successfully, access the *RaytracingTier* field (which specifies the supported ray tracing tier) of the now-populated **D3D12_FEATURE_DATA_D3D12_OPTIONS5** structure.

For more info, see [Capability Querying](https://learn.microsoft.com/windows/desktop/direct3d12/capability-querying).

### Hardware support for DXGI Formats

To view tables of DXGI formats and hardware features, refer to:

* [DXGI Format Support for Direct3D Feature Level 12.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-1-formats)
* [DXGI Format Support for Direct3D Feature Level 12.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-0-formats)
* [DXGI Format Support for Direct3D Feature Level 11.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-1-feature-level-hardware)
* [DXGI Format Support for Direct3D Feature Level 11.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-0-feature-level-hardware)
* [Hardware Support for Direct3D 10Level9 Formats](https://learn.microsoft.com/previous-versions/ff471324(v=vs.85))
* [Format Support for Direct3D Feature Level 10.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-1-hardware)
* [Format Support for Direct3D Feature Level 10.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-0-hardware)

#### Examples

The [D3D1211on12](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::CheckFeatureSupport** as follows:

```cpp
inline UINT8 D3D12GetFormatPlaneCount(
    _In_ ID3D12Device* pDevice,
    DXGI_FORMAT Format
    )
{
    D3D12_FEATURE_DATA_FORMAT_INFO formatInfo = {Format};
    if (FAILED(pDevice->CheckFeatureSupport(D3D12_FEATURE_FORMAT_INFO, &formatInfo, sizeof(formatInfo))))
    {
        return 0;
    }
    return formatInfo.PlaneCount;
}

```

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)