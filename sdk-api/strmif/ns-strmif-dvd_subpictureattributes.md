# DVD_SubpictureAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_SubpictureAttributes` structure contains information about the DVD subpicture. The [IDvdInfo2::GetSubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getsubpictureattributes) method fills in a `DVD_SubpictureAttributes` structure for a specified stream.

## Members

### `Type`

Variable of type [DVD_SUBPICTURE_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_subpicture_type) that indicates whether the subpicture contains language-related content.

### `CodingMode`

Variable of type [DVD_SUBPICTURE_CODING](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_subpicture_coding) that indicates how the subpicture graphics stream is encoded.

### `Language`

Variable of type LCID that identifies the subpicture language if Type equals DVD_SPType_Language.

### `LanguageExtension`

Variable of type [DVD_SUBPICTURE_LANG_EXT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_subpicture_lang_ext) that identifies the subpicture language extension if Type equals DVD_SPType_Language.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)