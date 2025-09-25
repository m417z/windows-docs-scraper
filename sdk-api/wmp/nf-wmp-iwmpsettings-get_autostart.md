# IWMPSettings::get_autoStart

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_autoStart** method retrieves a value indicating whether the current media item begins playing automatically.

## Parameters

### `pfAutoStart` [out]

Pointer to a **VARIANT_BOOL** that indicates whether the current media item begins playing automatically. The default is **TRUE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *pfAutoStart* is **TRUE**, the media item will begin playing when **IWMPCore::put_URL**, **IWMPCore::put_currentPlaylist**, or **IWMPCore::put_currentMedia** is called. Otherwise, the media item will not start playing until the **IWMPControls::play** method is called.

*pfAutoStart* for the full mode of Windows Media Player can be set globally by external events (such as loading a CD). Skins and remoted Player controls cannot expect a default value because they both employ the full mode Windows Media Player playback engine.

## See also

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPCore::put_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentmedia)

[IWMPCore::put_currentPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentplaylist)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::put_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_autostart)