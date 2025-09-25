# IWMPNetwork::get_downloadProgress

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_downloadProgress** method retrieves the percentage of the download completed.

## Parameters

### `plDownloadProgress` [out]

Pointer to a **long** containing the download progress.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the Windows Media Player control is connected to a digital media file that can be played and downloaded at the same time, the **get_downloadProgress** method retrieves the percentage of the total file that has been downloaded. This feature is currently supported only for digital media files downloaded from web servers. The following file formats can be downloaded and played simultaneously:

* Advanced Systems Format (ASF)
* Windows Media Audio (WMA)
* Windows Media Video (WMV)
* MP3
* MPEG
* WAV

In addition, some AVI files can be downloaded and played simultaneously.

Use the **IWMPEvents::Buffering** event to determine when buffering starts or stops.

## See also

[IWMPEvents::Buffering](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-buffering)

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)