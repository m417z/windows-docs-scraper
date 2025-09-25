# IWMPEvents::Buffering

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Buffering** event occurs when the Windows Media Player control begins or ends buffering.

## Parameters

### `Start` [in]

Specifies whether buffering has begun or ended. A value of true indicates that it has begun; a value of false indicates that it has ended.

## Remarks

Use this event to determine when buffering or downloading starts or stops. You can use the same event block for both cases and test **IWMPNetwork::get_bufferingProgress** and **IWMPNetwork::get_downloadProgress** to determine whether Windows Media Player is currently buffering or downloading content.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[IWMPNetwork::get_bufferingProgress](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-get_bufferingprogress)

[IWMPNetwork::get_downloadProgress](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-get_downloadprogress)