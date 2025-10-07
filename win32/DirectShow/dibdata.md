# DIBDATA structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DIBDATA` structure contains information about a GDI device-independent bitmap (DIB).

## Members

**PaletteVersion**

This member should be incremented whenever the palette changes.

**DibSection**

**DIBSECTION** structure that contains information about the DIB. See the GDI documentation for details.

**hBitmap**

Handle to the bitmap.

**hMapping**

Handle to a file-mapping object that is used to share memory between GDI and a [**CImageSample**](https://learn.microsoft.com/windows/win32/directshow/cimagesample) object.

**pBase**

Address of the bitmap.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Winutil.h (include Streams.h) |

