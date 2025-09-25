# DXGI_SAMPLE_DESC structure

## Description

Describes multi-sampling parameters for a resource.

## Members

### `Count`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of multisamples per pixel.

### `Quality`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The image quality level. The higher the quality, the lower the performance. The valid range is between zero and one less than the level returned
by [ID3D10Device::CheckMultisampleQualityLevels](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkmultisamplequalitylevels) for Direct3D 10 or [ID3D11Device::CheckMultisampleQualityLevels](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkmultisamplequalitylevels) for Direct3D 11.

For Direct3D 10.1 and Direct3D 11, you can use two special quality level values. For more information about these quality level values, see Remarks.

## Remarks

This structure is a member of the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure.

The default sampler mode, with no anti-aliasing, has a count of 1 and a quality level of 0.

If multi-sample antialiasing is being used, all bound render targets and depth buffers must have the same sample counts and quality levels.

|  |
| --- |
| Differences between Direct3D 10.0 and Direct3D 10.1 and between Direct3D 10.0 and Direct3D 11:<br><br>Direct3D 10.1 has defined two standard quality levels: **D3D10_STANDARD_MULTISAMPLE_PATTERN** and **D3D10_CENTER_MULTISAMPLE_PATTERN** in the **D3D10_STANDARD_MULTISAMPLE_QUALITY_LEVELS** enumeration in D3D10_1.h.<br><br>Direct3D 11 has defined two standard quality levels: **D3D11_STANDARD_MULTISAMPLE_PATTERN** and **D3D11_CENTER_MULTISAMPLE_PATTERN** in the [D3D11_STANDARD_MULTISAMPLE_QUALITY_LEVELS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_standard_multisample_quality_levels) enumeration in D3D11.h. |

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)