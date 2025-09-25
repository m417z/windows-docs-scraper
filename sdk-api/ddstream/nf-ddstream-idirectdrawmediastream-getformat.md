# IDirectDrawMediaStream::GetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves the current media stream's format and, optionally, its desired format.

## Parameters

### `pDDSDCurrent` [out]

Pointer to a DirectDraw surface description that will contain the current media stream's format.

### `ppDirectDrawPalette` [out]

Address of a pointer to an **IDirectDrawPalette** interface if one exists.

### `pDDSDDesired` [out]

Pointer to a DirectDraw surface description that will contain the current media stream's desired format.

### `pdwFlags` [out]

Pointer to the flags set in a **DDSURFACEDESC** structure. Flags of interest include:

| Flag | Description |
| --- | --- |
| DDSD_CAPS | Indicates that the surface capability member of the structure is valid. |
| DDSD_HEIGHT | Indicates that the height member of the structure is valid. |
| DDSD_PIXELFORMAT | Indicates that the pixel format member of the structure is valid. |
| DDSD_WIDTH | Indicates that the width member of the structure is valid. |

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **DDERR_INVALIDPARAMS** | One of the DirectDraw surface parameters is invalid. |
| **E_POINTER** | One or more of the required parameters is invalid. |
| **S_OK** | Success. |

## Remarks

After you call this method, you can either conform to the current format or attempt to change the format by calling the [IDirectDrawMediaStream::SetFormat](https://learn.microsoft.com/windows/desktop/api/ddstream/nf-ddstream-idirectdrawmediastream-setformat) method.

All of this method's parameters are optional; set any of them to **NULL** to indicate that you don't want to retrieve that information.

To perform a progressive render, create a single sample and repeatedly use that sample for successive frames of video. Video decompressors use this technique to do partial updates to the previous frame.

You must initialize the *dwSize* member of the **DDSURFACEDESC** structure before calling this method.

The DDSD_CAPS flag will return one of the values listed in the **DDSCAPS** structure or DDSCAPS_DATAEXCHANGE, which is defined as DDSCAPS_SYSTEMMEMORY|DDSCAPS_VIDEOMEMORY in Ddrawex.h.

## See also

[IDirectDrawMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawmediastream)