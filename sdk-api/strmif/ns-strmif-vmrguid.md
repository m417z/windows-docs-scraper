# VMRGUID structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The [VMRMONITORINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrmonitorinfo) structure and is used to identify a monitor on the system (VMR-7 only).

## Members

### `pGUID`

Pointer to the GUID member of the structure. **pGUID** is **NULL** if the monitor is the default DirectDraw device.

### `GUID`

Specifies the GUID for the monitor.

## Remarks

In DirectX 9.0 and later, the monitor is identified by an integer index, not by a GUID.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)