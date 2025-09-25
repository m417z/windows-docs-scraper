# IDvdControl2::AcceptParentalLevelChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AcceptParentalLevelChange` method accepts or rejects a request from the DVD Navigator to play content at a higher parental management level.

## Parameters

### `bAccept` [in]

Flag that indicates whether the application accepts the parental management level change. Specify **TRUE** to accept the change and play the higher-level content, or **FALSE** to reject the change.

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

A temporary parental management level (PML) command is a marker on the DVD disc indicating that the content that follows has a PML higher than the level specified for the title as a whole. This marker also contains instructions on where to branch depending on whether the change is accepted or rejected. If you specify **FALSE**, the DVD Navigator follows the rejected branch on the disc. If you specify **TRUE**, the DVD Navigator follows the branch to the higher-level content.

Use `AcceptParentalLevelChange` in conjunction with the [SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) method. The sequence of events is as follows: First, call **SetOption**(DVD_NotifyParentalLevelChange, **TRUE**) to tell the DVD Navigator to always wait after sending an EC_DVD_PARENTAL_LEVEL_CHANGE event notification to the application. In your event handler, implement code to determine whether to accept or reject the change, and then call `AcceptParentalLevelChange` to notify the DVD Navigator of the decision.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None | All |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Enforcing Parental Management Levels](https://learn.microsoft.com/windows/desktop/DirectShow/enforcing-parental-management-levels)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)