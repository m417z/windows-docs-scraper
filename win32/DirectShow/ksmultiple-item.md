# KSMULTIPLE\_ITEM structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `KSMULTIPLE_ITEM` structure describes the size and count of variable-length properties on kernel-mode pins.

## Members

**Size**

Size of the returned memory block, in bytes. The size includes the **KSMULTIPLE\_ITEM** structure and the items that follow it.

**Count**

Specifies the total number of items that follow this structure.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------|
| Header<br> | Ks.h |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

[**IKsPin::KsQueryMediums**](https://learn.microsoft.com/windows/win32/directshow/ikspin-ksquerymediums)

[**REGPINMEDIUM**](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpinmedium)

