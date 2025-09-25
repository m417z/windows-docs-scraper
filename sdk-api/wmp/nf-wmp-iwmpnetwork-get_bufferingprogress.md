# IWMPNetwork::get_bufferingProgress

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_bufferingProgress** method retrieves the percentage of buffering completed.

## Parameters

### `plBufferingProgress` [out]

Pointer to a **long** containing the buffering progress.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Each time playback is stopped and restarted, the value retrieved from this method is zero. It is not reset if playback is paused.

Buffering only applies to streaming content. This method retrieves valid information only during run time when the URL for playback is set using the **IWMPCore::put_URL** method.

Use the **IWMPEvents::Buffering** event to determine when buffering starts or stops.

## See also

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPEvents::Buffering](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-buffering)

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)