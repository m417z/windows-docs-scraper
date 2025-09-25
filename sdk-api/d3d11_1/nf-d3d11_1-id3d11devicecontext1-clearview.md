# ID3D11DeviceContext1::ClearView

## Description

Sets all the elements in a resource view to one value.

## Parameters

### `pView` [in]

A pointer to the [ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view) interface that represents the resource view to clear.

### `Color` [in]

A 4-component array that represents the color to use to clear the resource view.

### `pRect` [in, optional]

An array of [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect) structures for the rectangles in the resource view to clear. If **NULL**, **ClearView** clears the entire surface.

### `NumRects`

Number of rectangles in the array that the *pRect* parameter specifies.

## Remarks

**ClearView** works only on render-target views (RTVs), depth/stencil views (DSVs) on depth-only resources (resources with no stencil component), unordered-access views (UAVs), or any video view of a [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) surface. The runtime drops invalid calls. Empty rectangles in the *pRect* array are a no-op. A rectangle is empty if the top value equals the bottom value or the left value equals the right value.

**ClearView** doesn’t support 3D textures.

**ClearView** applies the same color value to all array slices in a view; all rectangles in the *pRect* array correspond to each array slice. The *pRect* array of rectangles is a set of areas to clear on a single surface. If the view is an array, **ClearView** clears all the rectangles on each array slice individually.

When you apply rectangles to buffers, set the top value to 0 and the bottom value to 1 and set the left value and right value to describe the extent within the buffer. When the top value equals the bottom value or the left value equals the right value, the rectangle is empty and a no-op is achieved.

The driver converts and clamps color values to the destination format as appropriate per Direct3D conversion rules. For example, if the format of the view is [DXGI_FORMAT_R8G8B8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), the driver clamps inputs to 0.0f to 1.0f (+INF -> 1.0f (0XFF)/NaN -> 0.0f).

If the format is integer, such as [DXGI_FORMAT_R8G8B8A8_UINT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), the runtime interprets inputs as integral floats. Therefore, 235.0f maps to 235 (rounds to zero, out of range/INF values clamp to target range, and NaN to 0).

Here are the color mappings:

* Color[0]: R (or Y for video)
* Color[1]: G (or U/Cb for video)
* Color[2]: B (or V/Cr for video)
* Color[3]: A

For video views with YUV or YCbBr formats, **ClearView** doesn't convert color values. In situations where the format name doesn’t indicate _UNORM, _UINT, and so on, **ClearView** assumes _UINT. Therefore, 235.0f maps to 235 (rounds to zero, out of range/INF values clamp to target range, and NaN to 0).

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)