# IDvdControl2::SelectAndActivateButton

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectAndActivateButton` method selects and activates the specified menu button.

## Parameters

### `ulButton` [in]

Value from 1 through 36 that specifies the button to select and activate.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | *ulButton* is out of range. |
| **E_UNEXPECTED** | The *ulButton* value is valid, but the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter couldn't activate it. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the operation. |

## Remarks

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Button_Select_and_Activate | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)

[Working With DVD Menus](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-menus)