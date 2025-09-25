# IDvdControl2::ActivateAtPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ActivateAtPosition` method activates the menu button under the mouse pointer position.

## Parameters

### `point` [in]

Point on the client window area, in screen pixel coordinates.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The click occurred in the highlighted button rectangle, and the button was successfully activated. |
| **E_INVALIDARG** | The point lies outside the valid video region. |
| **E_UNEXPECTED** | The button is present but is not working. |
| **VFW_E_DVD_INVALIDDOMAIN** | The DVD Navigator is not in a menu domain. |
| **VFW_E_DVD_NO_BUTTON** | There is no menu button under the mouse pointer position. |
| **VFW_E_DVD_OPERATION_INHIBITED** | The operation is inhibited by user operation (UOP) control. |

## Remarks

The mouse pointer coordinates are relative to the upper left of the client area, which isn't necessarily the video display area if the video is in letterbox format.

Use this method when the user is navigating through a menu by moving the mouse pointer directly over the menu buttons. If the user is using the relative buttons to navigate the menu, use [ActivateButton](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-activatebutton) rather than `ActivateAtPosition`.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Working With DVD Menus](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-menus)