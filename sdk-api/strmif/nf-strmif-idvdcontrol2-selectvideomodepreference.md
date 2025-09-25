# IDvdControl2::SelectVideoModePreference

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectVideoModePreference` method sets the specified video mode display (wide screen, letterbox, or pan-scan) for playback.

## Parameters

### `ulPreferredDisplayMode` [in]

Value that specifies the new display mode for DVD content. Member of the [DVD_PREFERRED_DISPLAY_MODE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_preferred_display_mode) enumeration.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |

## Remarks

This method changes the default video window's aspect ratio and can also specify a default aspect ratio conversion mechanism.

For anamorphic 16 x 9 source video, formed by stretching the 720 x 480 source video to a 16 x 9 aspect ratio.

**Widescreen** The 16 x 9 source video should be placed and stretched into the largest 16 x 9 area of the client output window. The highlights are relative to the inside of the 16 x 9 area. Black bars should be added to either the top/bottom or to the sides to maintain a 16 x 9 area.

**Pan Scan** The video shown is computed by taking a 4 x 3 subwindow from the stretched 16 x 9 video (the horizontal offset is provided in the MPEG-2 video's window's offset). The 4 x 3 subwindow is placed into the largest 4 x 3 area of the output client window. The highlight's coordinates are relative to the 4 x 3 output window (and have no relationship to the source 16 x 9 video). Black bars should be added to either the top/bottom or to the sides to maintain a 4 x 3 area.

**Letterbox** A 4 x 3 display area is formed by taking the largest 4 x 3 area of the output client window. Black bars should be added to either the top/bottom or to the sides to maintain a 4 x 3 area. The source 16 x 9 video is placed in the largest 16 x 9 subwindow inside of the 4 x 3 subwindow. Black bars should be added to the top and bottom of the subwindow to maintain a 16 x 9 area. The highlight's coordinates are relative to the 4 x 3 subwindow (and have no relationship to the source 16 x 9 video). It is technically possible for a disk to specify a highlight that lies outside of the 16 x 9 area (but still in the 4 x 3 window).

For 4 x 3 video, the video is placed in the largest 4 x 3 output area of the output client window. Black bars should be added to either the top/bottom or to the sides to maintain a 4 x 3 area.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Video_Presentation_Mode_Change | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title<br>* DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)