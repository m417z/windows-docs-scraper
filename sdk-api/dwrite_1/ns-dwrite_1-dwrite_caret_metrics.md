# DWRITE_CARET_METRICS structure

## Description

The **DWRITE_CARET_METRICS** structure specifies the metrics for caret placement in a font.

## Members

### `slopeRise`

Vertical rise of the caret in font design units. Rise / Run yields the caret angle. Rise = 1 for perfectly upright fonts (non-italic).

### `slopeRun`

Horizontal run of the caret in font design units. Rise / Run yields the caret angle. Run = 0 for perfectly upright fonts (non-italic).

### `offset`

Horizontal offset of the caret, in font design units, along the baseline for good appearance. Offset = 0 for perfectly upright fonts (non-italic).

## See also

[IDWriteFontFace1::GetCaretMetrics](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getcaretmetrics)