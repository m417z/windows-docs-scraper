# IDWriteFontFace2::GetRecommendedRenderingMode

## Description

Determines the recommended text rendering and grid-fit mode to be used based on the font, size, world transform, and measuring mode.

## Parameters

### `fontEmSize` [in]

Type: **FLOAT**

Logical font size in DIPs.

### `dpiX` [in]

Type: **FLOAT**

Number of pixels per logical inch in the horizontal direction.

### `dpiY` [in]

Type: **FLOAT**

Number of pixels per logical inch in the vertical direction.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

A [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix) structure that describes the world transform.

### `isSideways` [in]

Type: **BOOL**

Specifies whether the font is sideways. **TRUE** if the font is sideways; otherwise, **FALSE**.

### `outlineThreshold` [in]

Type: **[DWRITE_OUTLINE_THRESHOLD](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_outline_threshold)**

A [DWRITE_OUTLINE_THRESHOLD](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_outline_threshold)-typed value that specifies the quality of the graphics system's outline rendering, affects the size threshold above which outline rendering is used.

### `measuringMode` [in]

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

A [DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)-typed value that specifies the method used to measure during text layout. For proper glyph spacing, this method returns a rendering mode that is compatible with the specified measuring mode.

### `renderingParams` [in, optional]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

A pointer to a [IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams) interface for the rendering parameters object. This parameter is necessary in case the rendering parameters object overrides the rendering mode.

### `renderingMode` [out]

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)***

A pointer to a variable that receives a [DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)-typed value for the recommended rendering mode.

### `gridFitMode` [out]

Type: **[DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)***

A pointer to a variable that receives a [DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)-typed value for the recommended grid-fit mode.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFace2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontface2)