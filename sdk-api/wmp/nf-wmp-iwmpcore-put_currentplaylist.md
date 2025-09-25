# IWMPCore::put_currentPlaylist

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_currentPlaylist** method specifies the **IWMPPlaylist** interface that corresponds to the current playlist.

## Parameters

### `pPL` [in]

Pointer to an **IWMPPlaylist** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the **IWMPSettings::put_autoStart** method was invoked with an argument of true, file playback will begin automatically whenever you invoke **put_currentPlaylist**.

You can retrieve an **IWMPMedia** interface for a given media object by invoking the **IWMPPlaylist::get_Item** method.

## See also

[IWMPCore Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcore)

[IWMPCore::get_currentPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentplaylist)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)