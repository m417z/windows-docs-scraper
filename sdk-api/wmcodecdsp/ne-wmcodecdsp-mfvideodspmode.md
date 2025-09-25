# MFVideoDSPMode enumeration

## Description

Specifies the processing mode of the [Video Stabilization MFT](https://learn.microsoft.com/windows/desktop/medfound/video-stabilization-mft).

## Constants

### `MFVideoDSPMode_Passthrough:1`

Pass-through mode. Video stabilization is not applied.

### `MFVideoDSPMode_Stabilization:4`

Video stabilization is applied.

## Remarks

This enumeration is used with the [MF_VIDEODSP_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-videodsp-mode) attribute.

In pass-through mode, the MFT does not apply any processing to the video.

## See also

[MF_VIDEODSP_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-videodsp-mode)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Stabilization MFT](https://learn.microsoft.com/windows/desktop/medfound/video-stabilization-mft)