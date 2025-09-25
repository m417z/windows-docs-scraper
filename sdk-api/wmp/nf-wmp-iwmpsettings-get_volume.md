# IWMPSettings::get_volume

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_volume** method retrieves the current playback volume.

## Parameters

### `plVolume` [out]

Pointer to a **long** containing the volume level ranging from 0 to 100.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A value of zero specifies no volume (muted). A value of 100 specifies full volume. If no value is specified for this property, it defaults to the last volume setting established for Windows Media Player.

## See also

[IWMPSetting::put_volume](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_volume)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)