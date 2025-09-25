# IWMPContentPartnerCallback::DownloadTrack

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **DownloadTrack** method instructs Windows Media Player to download or not to download a particular media item.

## Parameters

### `cookie` [in]

A cookie that identifies a download session. Windows Media Player previously supplied this cookie to the content partner plug-in by calling [IWMPContentPartner::Download](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-download).

### `bstrTrackURL` [in]

The URL of the track to download.

### `dwServiceTrackID` [in]

The ID of the track in question.

### `bstrDownloadParams` [in]

Data that the online store wants to associate with the track in question. Windows Media Player does not interpret this data; it is meaningful only to the online store. Windows Media player passes this data back to the online store when it calls [IWMPContentPartner::DownloadTrackComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-downloadtrackcomplete).

### `hrDownload` [in]

An **HRESULT** that specifies whether to download the track. Any success code specifies that the Player should download the track. Any failure code specifies that the Player should not download the track.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For an explanation of how the Player and the plug-in work together to download a set of tracks, see [Downloading Media Content](https://learn.microsoft.com/windows/desktop/WMP/downloading-media-content).

This method must be called only after a license has been predelivered for the file. The file will be placed in the user's Music folder and automatically added to the library when downloading is complete.

## See also

[IWMPContentPartner::Download](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-download)

[IWMPContentPartner::DownloadTrackComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-downloadtrackcomplete)

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)