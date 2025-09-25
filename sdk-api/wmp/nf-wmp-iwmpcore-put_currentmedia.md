# IWMPCore::put_currentMedia

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_currentMedia** method specifies the **IWMPMedia** interface that corresponds to the current media item.

## Parameters

### `pMedia` [in]

Pointer to an **IWMPMedia** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the **IWMPSettings::put_autoStart** method was invoked with an argument of true, file playback will begin automatically whenever you invoke **put_currentMedia**.

You can retrieve an **IWMPMedia** interface for a given media item by invoking the **IWMPPlaylist::get_item** method.

## See also

[IWMPCore Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcore)

[IWMPCore::get_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentmedia)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPPlaylist::get_item](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-get_item)

[IWMPSettings::put_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_autostart)