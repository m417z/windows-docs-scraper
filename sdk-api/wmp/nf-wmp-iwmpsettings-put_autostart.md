# IWMPSettings::put_autoStart

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_autoStart** method specifies a value indicating whether the current media item begins playing automatically.

## Parameters

### `fAutoStart` [in]

**VARIANT_BOOL** indicating whether the current media item begins playing automatically. The default is **TRUE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **put_autoStart** method for the full mode of Windows Media Player can be set globally by external events (such as loading a CD). Therefore, there is no reliable default value for skins and remoted Player controls. This is because the playback engine of the full mode Player is used in both cases.

You should set **put_autoStart** to **FALSE** immediately before you set **IWMPCore::put_URL**, **IWMPCore::put_currentPlaylist**, or **IWMPCore::put_currentMedia** in skins and remoted Player controls if you wish to ensure that the media item does not start playing immediately. Also, unless you set **put_autostart** to **TRUE** immediately before specifying a media item, you should not rely on this setting as a substitute for using the **IWMPControls::play** method.

## See also

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPCore::put_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentmedia)

[IWMPCore::put_currentPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentplaylist)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::get_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_autostart)