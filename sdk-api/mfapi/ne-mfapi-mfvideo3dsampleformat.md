# MFVideo3DSampleFormat enumeration

## Description

Specifies how a 3D video frame is stored in a media sample.

## Constants

### `MFSampleExtension_3DVideo_MultiView:1`

Each view is stored in a separate buffer. The sample contains one buffer per view.

### `MFSampleExtension_3DVideo_Packed:0`

All of the views are stored in the same buffer. The sample contains a single buffer.

## Remarks

This enumeration is used with the [MFSampleExtension_3DVideo_SampleFormat](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-3dvideo-sampleformat) attribute.

The exact layout of the views in memory is specified by the following media type attributes:

* [MF_MT_VIDEO_3D_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-3d-format)
* [MF_MT_VIDEO_3D_FIRST_IS_LEFT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-3d-first-is-left)
* [MF_MT_VIDEO_3D_LEFT_IS_BASE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-3d-left-is-base)
* [MF_MT_VIDEO_3D_NUM_VIEWS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-3d-num-views)

## See also

Media Foundation Enumerations