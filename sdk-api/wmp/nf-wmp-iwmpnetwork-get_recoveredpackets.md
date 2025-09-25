# IWMPNetwork::get_recoveredPackets

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_recoveredPackets** method retrieves the number of recovered packets.

## Parameters

### `plRecoveredPackets` [out]

Pointer to a **long** containing the recovered packets.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Each time playback is stopped and restarted, the value retrieved from this method is reset to zero. The value is not reset if playback is paused.

This method retrieves valid information only during run time when the URL for playback is set by using the **IWMPCore::put_URL** method. The value will be zero when using the HTTP protocol, which is lossless.

## See also

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)