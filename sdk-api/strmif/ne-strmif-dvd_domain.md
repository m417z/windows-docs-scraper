# DVD_DOMAIN enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the DVD domains.

## Constants

### `DVD_DOMAIN_FirstPlay:1`

Performing default initialization of a DVD disc.

### `DVD_DOMAIN_VideoManagerMenu`

Displaying menus for whole disc.

### `DVD_DOMAIN_VideoTitleSetMenu`

Displaying menus for current title set.

### `DVD_DOMAIN_Title`

Displaying the current title.

### `DVD_DOMAIN_Stop`

The DVD Navigator is in the DVD Stop domain.

## Remarks

This enumeration is used in the [IDvdInfo2::GetCurrentDomain](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentdomain) method.

A domain is a logical space on a DVD disc. When the DVD Navigator is displaying the disc's main menu, it is said to be in the Video Manager domain. When it is displaying a menu specific to a title, it is in the Video Title Set domain. When it is playing video, it is the Title domain. When the user issues a Stop command, the Navigator goes into the Stop domain.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetCurrentDomain](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentdomain)