# REGPINMEDIUM structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `REGPINMEDIUM` structure describes a pin medium for registration through the [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) interface.

## Members

### `clsMedium`

GUID that specifies the medium.

### `dw1`

Variable of type **DWORD** that specifies the instance of this medium. This is necessary when two identical devices are present on the host system.

### `dw2`

Not used.

## Remarks

A *medium* identifies a hardware path of communication that exists within a single hardware device or between two devices. Register mediums if your filter is built on kernel streaming pins and needs to connect to other such filters.

This structure is equivalent to the [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structure, which is used by kernel streaming drivers.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows/desktop/DirectShow/ksmultiple-item)