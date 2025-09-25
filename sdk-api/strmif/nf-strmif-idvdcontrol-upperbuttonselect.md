# IDvdControl::UpperButtonSelect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdControl** interface is deprecated. Use [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) instread.

Selects the upper directional button from the displayed menu.

## Return value

Returns an **HRESULT** value .

## Remarks

On physical or electronic remote control devices, there is often a group of four directional buttons used for certain types of operations (such as menu navigation). This method tells DirectShow that something (the user, probably) triggered the upper directional button.

Selecting a DVD button simply highlights the button but does not activate the button. Selecting is the Windows equivalent of tabbing to a button but not pressing the SPACEBAR or ENTER key. Activating is the Windows equivalent of pressing the SPACEBAR or ENTER key after tabbing to a button.

This method returns an error unless the domain is DVD_DOMAIN_VideoManagerMenu, DVD_DOMAIN_VideoTitleSetMenu, or DVD_DOMAIN_Title. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol)