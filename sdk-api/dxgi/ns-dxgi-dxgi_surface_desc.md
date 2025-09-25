# DXGI_SURFACE_DESC structure

## Description

Describes a surface.

## Members

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value describing the surface width.

### `Height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value describing the surface height.

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A member of the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumerated type that describes the surface format.

### `SampleDesc`

Type: **[DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)**

A member of the [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that describes multi-sampling parameters for the surface.

## Remarks

This structure is used by the [GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface-getdesc) and [CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice-createsurface) methods.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)