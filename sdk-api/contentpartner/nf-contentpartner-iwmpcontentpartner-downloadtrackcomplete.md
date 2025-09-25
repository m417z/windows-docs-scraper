# IWMPContentPartner::DownloadTrackComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **DownloadTrackComplete** method notifies the content partner plug-in that Windows Media Player has finished downloading a track or that the download attempt failed.

## Parameters

### `hrResult` [in]

**HRESULT** indicating success or failure of the download. Any success code indicates that the Player successfully downloaded the track. Any failure code indicates that the Player failed to download the track.

### `contentID` [in]

Content ID of the track in question.

### `downloadTrackParam` [in]

Parameter that the plug-in previously passed to [IWMPContentPartnerCallback::DownloadTrack](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-downloadtrack). This parameter is meaningful only to the online store; it is not interpreted by Windows Media Player.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To learn how the Player and the plug-in work together to download a set of tracks, see [Downloading Media Content](https://learn.microsoft.com/windows/desktop/WMP/downloading-media-content).

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[IWMPContentPartner::Download](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-download)