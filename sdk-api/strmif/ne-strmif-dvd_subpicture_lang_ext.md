# DVD_SUBPICTURE_LANG_EXT enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the possible language extensions in a specified subpicture stream.

## Constants

### `DVD_SP_EXT_NotSpecified:0`

Indicates that no language extensions are present.

### `DVD_SP_EXT_Caption_Normal:1`

Indicates that the specified stream contains normal captions.

### `DVD_SP_EXT_Caption_Big:2`

Indicates that the specified stream contains big captions.

### `DVD_SP_EXT_Caption_Children:3`

Indicates that the specified stream contains captions for children.

### `DVD_SP_EXT_CC_Normal:5`

Indicates that the specified stream contains normal closed captions.

### `DVD_SP_EXT_CC_Big:6`

Indicates that the specified stream contains big closed captions.

### `DVD_SP_EXT_CC_Children:7`

Indicates that the specified stream contains closed captions for children.

### `DVD_SP_EXT_Forced:9`

Indicates that the subpicture stream is forcedly activated, meaning that the application will not be able to turn it off.

### `DVD_SP_EXT_DirectorComments_Normal:13`

Indicates that the specified stream contains normal-sized director's comments.

### `DVD_SP_EXT_DirectorComments_Big:14`

Indicates that the specified stream contains large-sized director's comments.

### `DVD_SP_EXT_DirectorComments_Children:15`

Indicates that the specified stream contains director's comments for children.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdControl2::SelectDefaultSubpictureLanguage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectdefaultsubpicturelanguage)

[IDvdInfo2::GetDefaultSubpictureLanguage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdefaultsubpicturelanguage)