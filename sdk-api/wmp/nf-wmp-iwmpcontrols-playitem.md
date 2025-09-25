# IWMPControls::playItem

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **playItem** method plays the specified media item.

## Parameters

### `pIWMPMedia` [in]

Pointer to an **IWMPMedia** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The media item will load and play automatically, regardless of the value retrieved by the **IWMPSettings::get_autoStart** method. To load an item without playing it automatically, pass in a **VARIANT_BOOL** set to **FALSE** in the **IWMPSettings::put_autoStart** method and specify a URL in **IWMPCore::put_URL**, after which **IWMPControls::play** can be called to start playing the item.

Note

**playItem** works only with items retrieved from **IWMPCore::get_currentPlaylist**. Calling **playItem** with a reference to a saved media item is not supported.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPCore::get_currentPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentplaylist)

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPPlaylist::get_item](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-get_item)

[IWMPSettings::get_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_autostart)

[IWMPSettings::put_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_autostart)