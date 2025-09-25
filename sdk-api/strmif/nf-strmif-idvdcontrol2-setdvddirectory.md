# IDvdControl2::SetDVDDirectory

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDVDDirectory` method sets the DVD drive that the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter will read from.

## Parameters

### `pszwPath` [in]

Pointer to a wide-character string that specifies the path of the root directory.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pszwPath* parameter points to an invalid DVD path, or a DVD drive is not found while enumerating. |
| **E_UNEXPECTED** | The DVD Navigator is not initialized. |
| **VFW_E_DVD_INVALIDDOMAIN** | Invalid domain. For details, see Remarks. |

## Remarks

If *pszwPath* is **NULL**, the DVD Navigator tries to select a DVD volume on any available drive. On startup, the DVD Navigator automatically looks for a drive, starting at drive C, with a VIDEO_TS folder in the root folder. It is therefore only necessary to call `SetDVDDirectory` when you have more than one DVD drive on a machine, or if your DVD drive letter is A or B. When specifying the path, include the video_ts folder.

| C++ |
| --- |
| ``` SetDVDDirectory(L"e:\\video_ts"); ``` |

Some DVD volumes may have their video in a directory named something other than "video_ts." The general idea is that an additional "DVD volume" (the set of .IFO. VOB, and .BUP files that would normally be stored in the VIDEO_TS directory) can be placed in a subdirectory on the disc. By changing the root to point to this directory, MSWebDVD will operate on this separate DVD volume. A new set of menus, titles, and so on will be available, independent of the titles in the VIDEO_TS root, which will no longer be accessible. Such directories are called "hidden directories." The following example shows how to set a hidden directory as the root, where "hidden" is a placeholder for whatever name the disc authors have given to the directory.

| C++ |
| --- |
| ``` SetDVDDirectory(L"d:\\webdvd\\hidden"); ``` |

If the filter graph is running and the DVD Navigator finds a DVD in the directory specified by *pszwPath*, the DVD Navigator automatically begins playing the disc. This conforms with the DVD specification and ensures that the new disc is initialized properly. If you do not want the new disc to play automatically after `SetDVDDirectory` returns, you must set the DVD_ResetOnStop flag in [IDvdControl2::SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) to **TRUE** and stop the filter graph through a call to [IMediaControl::Stop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stop) on the Filter Graph Manager. If DVD_ResetOnStop is set to **FALSE**, then `SetDVDDirectory` returns VFW_E_DVD_INVALIDDOMAIN.

This method is demonstrated in the DVDSample application in **CDvdCore::SetDirectory**.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None | DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)