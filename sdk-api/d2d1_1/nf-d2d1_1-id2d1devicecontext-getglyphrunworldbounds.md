# ID2D1DeviceContext::GetGlyphRunWorldBounds

## Description

 Gets the world-space bounds in DIPs of the glyph run using the device
context DPI.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The origin of the baseline for the glyph run.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The glyph run to render.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The DirectWrite measuring mode that indicates how glyph metrics are used to measure text when it is formatted.

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The bounds of the glyph run in DIPs and in world space.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

The image bounds reflect the current DPI, unit mode, and world transform of the context.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)