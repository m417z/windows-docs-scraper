# D3D11_MAPPED_SUBRESOURCE structure

## Description

Provides access to subresource data.

## Members

### `pData`

Type: **void***

Pointer to the data. When [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) provides the pointer, the runtime ensures that the pointer has a specific alignment, depending on the following feature levels:

* For [D3D_FEATURE_LEVEL_10_0](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) and higher, the pointer is aligned to 16 bytes.
* For lower than [D3D_FEATURE_LEVEL_10_0](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), the pointer is aligned to 4 bytes.

### `RowPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The row pitch, or width, or physical size (in bytes) of the data.

### `DepthPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth pitch, or width, or physical size (in bytes)of the data.

## Remarks

This structure is used in a call to [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map).

The values in these members tell you how much data you can view:

* **pData** points to row 0 and depth slice 0.
* **RowPitch** contains the value that the runtime adds to **pData** to move from row to row, where each row contains multiple pixels.
* **DepthPitch** contains the value that the runtime adds to **pData** to move from depth slice to depth slice, where each depth slice contains multiple rows.

When **RowPitch** and **DepthPitch** are not appropriate for the resource type, the runtime might set their values to 0. So, don't use these values for anything other than iterating over rows and depth. Here are some examples:

* For [Buffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-buffer) and [Texture1D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture1d), the runtime assigns values that aren't 0 to **RowPitch** and **DepthPitch**. For example, if a **Buffer** contains 8 bytes, the runtime assigns values to **RowPitch** and **DepthPitch** that are greater than or equal to 8.
* For [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d), the runtime still assigns a value that isn't 0 to **DepthPitch**, assuming that the field isn't used.

**Note** The runtime might assign values to **RowPitch** and **DepthPitch** that are larger than anticipated because there might be padding between rows and depth.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)