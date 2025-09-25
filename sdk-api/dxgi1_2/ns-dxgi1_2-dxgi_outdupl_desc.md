# DXGI_OUTDUPL_DESC structure

## Description

The DXGI_OUTDUPL_DESC structure describes the dimension of the output and the surface that contains the desktop image. The format of the desktop image is always [DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

## Members

### `ModeDesc`

A [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) structure that describes the display mode of the duplicated output.

### `Rotation`

A member of the [DXGI_MODE_ROTATION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85)) enumerated type that describes how the duplicated output rotates an image.

### `DesktopImageInSystemMemory`

Specifies whether the resource that contains the desktop image is already located in system memory. **TRUE** if the resource is in system memory; otherwise, **FALSE**. If this value is **TRUE** and the application requires CPU access, it can use the [IDXGIOutputDuplication::MapDesktopSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-mapdesktopsurface) and [IDXGIOutputDuplication::UnMapDesktopSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-unmapdesktopsurface) methods to avoid copying the data into a staging buffer.

## Remarks

This structure is used by [GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getdesc).

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)