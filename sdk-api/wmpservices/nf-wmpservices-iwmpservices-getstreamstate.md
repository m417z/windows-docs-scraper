# IWMPServices::GetStreamState

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPServices::GetStreamState** method retrieves information about the current play state of the stream.

## Parameters

### `pState` [in]

A pointer to a **WMPServices_StreamState** enumeration value.

## Return value

The method returns an **HRESULT**.

## Remarks

The stream is stopped, paused, or playing.

## See also

[IWMPServices Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpservices)

[WMPServices_StreamState](https://learn.microsoft.com/windows/desktop/api/wmpservices/ne-wmpservices-wmpservices_streamstate)