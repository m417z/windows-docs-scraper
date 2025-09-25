# D3D11_VIEWPORT structure

## Description

Defines the dimensions of a viewport.

## Members

### `TopLeftX`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

X position of the left hand side of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.

### `TopLeftY`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Y position of the top of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.

### `Width`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the viewport.

### `Height`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the viewport.

### `MinDepth`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum depth of the viewport. Ranges between 0 and 1.

### `MaxDepth`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum depth of the viewport. Ranges between 0 and 1.

## Remarks

In all cases, **Width** and **Height** must be >= 0 and **TopLeftX** + **Width** and **TopLeftY** + **Height** must be <= D3D11_VIEWPORT_BOUNDS_MAX.

|  |
| --- |
| Viewport Sizes and Feature Level Support Differences between Direct3D 11 and Direct3D 10:<br><br>The range for the minimum and maximum viewport size is dependent on the feature level defined by [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level).<br><br>* Direct3D 11 supports fractional viewports; the parameter types are floating-point numbers. The feature level, D3D_FEATURE_LEVEL_11_0, supports (D3D11_VIEWPORT_BOUNDS_MIN, D3D11_VIEWPORT_BOUNDS_MAX) values between (-32768, 32,767).<br>* Direct3D 10 does not support fractional viewports. The feature levels, D3D_FEATURE_LEVEL_10_1 (or below), supports (D3D10_VIEWPORT_BOUNDS_MIN, D3D10_VIEWPORT_BOUNDS_MAX) values between (-16384, 16383). |

**Note** Even though you specify float values to the members of the **D3D11_VIEWPORT** structure for the *pViewports* array in a call to [ID3D11DeviceContext::RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetviewports) for [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9_x, **RSSetViewports** uses DWORDs internally. Because of this behavior, when you use a negative top left corner for the viewport, the call to **RSSetViewports** for feature levels 9_x fails. This failure occurs because **RSSetViewports** for 9_x casts the floating point values into unsigned integers without validation, which results in integer overflow.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)