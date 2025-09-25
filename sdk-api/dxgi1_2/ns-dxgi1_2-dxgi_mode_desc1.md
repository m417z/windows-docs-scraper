# DXGI_MODE_DESC1 structure

## Description

Describes a display mode and whether the display mode supports stereo.

## Members

### `Width`

A value that describes the resolution width.

### `Height`

A value that describes the resolution height.

### `RefreshRate`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that describes the refresh rate in hertz.

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that describes the display format.

### `ScanlineOrdering`

A [DXGI_MODE_SCANLINE_ORDER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173067(v=vs.85))-typed value that describes the scan-line drawing mode.

### `Scaling`

A [DXGI_MODE_SCALING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173066(v=vs.85))-typed value that describes the scaling mode.

### `Stereo`

Specifies whether the full-screen display mode is stereo. **TRUE** if stereo; otherwise, **FALSE**.

## Remarks

**DXGI_MODE_DESC1** is identical to [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) except that **DXGI_MODE_DESC1** includes the **Stereo** member.

This structure is used by the [GetDisplayModeList1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-getdisplaymodelist1) and [FindClosestMatchingMode1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-findclosestmatchingmode1) methods.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)