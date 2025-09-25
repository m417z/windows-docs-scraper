# MFVideo3DFormat enumeration

## Description

Specifies how 3D video frames are stored in memory.

## Constants

### `MFVideo3DSampleFormat_BaseView:0`

The base view is stored in a single buffer. The other view is discarded.

### `MFVideo3DSampleFormat_MultiView:1`

Each media sample contains multiple buffers, one for each view.

### `MFVideo3DSampleFormat_Packed_LeftRight:2`

Each media sample contains one buffer, with both views packed side-by-side into a single frame.

### `MFVideo3DSampleFormat_Packed_TopBottom:3`

Each media sample contains one buffer, with both views packed top-and-bottom into a single frame.

## Remarks

This enumeration is used with the [MF_MT_VIDEO_3D_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-3d-format) attribute.

## See also

Media Foundation Enumerations