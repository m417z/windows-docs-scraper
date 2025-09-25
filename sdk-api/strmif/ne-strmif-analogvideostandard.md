# AnalogVideoStandard enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AnalogVideoStandard** enumeration specifies the format of an analog television signal.

## Constants

### `AnalogVideo_None:0`

Digital sensor.

### `AnalogVideo_NTSC_M:0x1`

NTSC (M) standard, 7.5 IRE black.

### `AnalogVideo_NTSC_M_J:0x2`

NTSC (M) standard, 0 IRE black (Japan).

### `AnalogVideo_NTSC_433:0x4`

NTSC-433.

### `AnalogVideo_PAL_B:0x10`

PAL-B standard.

### `AnalogVideo_PAL_D:0x20`

PAL (D) standard.

### `AnalogVideo_PAL_G:0x40`

### `AnalogVideo_PAL_H:0x80`

PAL (H) standard.

### `AnalogVideo_PAL_I:0x100`

PAL (I) standard.

### `AnalogVideo_PAL_M:0x200`

PAL (M) standard.

### `AnalogVideo_PAL_N:0x400`

PAL (N) standard.

### `AnalogVideo_PAL_60:0x800`

PAL-60 standard.

### `AnalogVideo_SECAM_B:0x1000`

SECAM (B) standard.

### `AnalogVideo_SECAM_D:0x2000`

SECAM (D) standard.

### `AnalogVideo_SECAM_G:0x4000`

SECAM (G) standard.

### `AnalogVideo_SECAM_H:0x8000`

SECAM (H) standard.

### `AnalogVideo_SECAM_K:0x10000`

SECAM (K) standard.

### `AnalogVideo_SECAM_K1:0x20000`

SECAM (K1) standard.

### `AnalogVideo_SECAM_L:0x40000`

SECAM (L) standard.

### `AnalogVideo_SECAM_L1:0x80000`

SECAM (L1) standard.

### `AnalogVideo_PAL_N_COMBO:0x100000`

Combination (N) PAL standard (Argentina).

### `AnalogVideoMask_MCE_NTSC`

### `AnalogVideoMask_MCE_PAL`

### `AnalogVideoMask_MCE_SECAM`

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMTVTuner](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvtuner)