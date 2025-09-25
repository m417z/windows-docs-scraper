# IWMPContentPartner::Download

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Download** method initiates the download of a set of media items.

## Parameters

### `pInfo` [in]

Pointer to an [IWMPContentContainerList](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentcontainerlist) interface that describes the content to download.

### `cookie` [in]

A cookie that represents the download request.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method initiates the process of inspecting the container list passed in *pInfo* and then returns immediately. As the plug-in inspects the container list, it calls [IWMPContentPartnerCallback::DownloadTrack](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-downloadtrack) once for each track in the container list. For more information about the download procedure, see [Downloading Media Content](https://learn.microsoft.com/windows/desktop/WMP/downloading-media-content).

## See also

[IWMPContentContainerList Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentcontainerlist)

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[IWMPContentPartner::DownloadTrackComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-downloadtrackcomplete)