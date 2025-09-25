# IWMPSettings::get_isAvailable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_isAvailable** method indicates whether a specified action can be performed.

## Parameters

### `bstrItem` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| AutoStart | Determines whether the **put_autoStart** method can be used to specify that Windows Media Player starts playback automatically. |
| Balance | Determines whether the **put_balance** method can be used to set the stereo balance. |
| BaseURL | Determines whether the **put_baseURL** method can be used to specify a base URL. |
| DefaultFrame | Determines whether the **put_defaultFrame** method can be used to specify the default frame. |
| EnableErrorDialogs | Determines whether the **put_enableErrorDialogs** method can be used to enable or disable displaying error dialog boxes. |
| GetMode | Determines whether the **getMode** method can be used to retrieve the current loop or shuffle mode. |
| InvokeURLs | Determines whether the **put_invokeURLs** method can be used to specify whether URL events should launch a Web browser. |
| Mute | Determines whether the **put_mute** method can be used to specify whether the audio output is on or off. |
| PlayCount | Determines whether the **put_playCount** method can be used to specify the number times a media item will play. |
| Rate | Determines whether the **put_rate** method can be used to set the playback rate. |
| SetMode | Determines whether the **setMode** method can be used to specify the current loop or shuffle mode. |
| Volume | Determines whether the **put_volume** method can be used to specify the audio volume. |

### `pIsAvailable` [out]

Pointer to a **VARIANT_BOOL** indicating whether the specified action can be performed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::getMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-getmode)

[IWMPSettings::put_autoStart](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_autostart)

[IWMPSettings::put_balance](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_balance)

[IWMPSettings::put_baseURL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_baseurl)

[IWMPSettings::put_defaultFrame](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_defaultframe)

[IWMPSettings::put_enableErrorDialogs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_enableerrordialogs)

[IWMPSettings::put_invokeURLs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_invokeurls)

[IWMPSettings::put_mute](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_mute)

[IWMPSettings::put_playCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_playcount)

[IWMPSettings::put_rate](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_rate)

[IWMPSettings::put_volume](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_volume)

[IWMPSettings::setMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-setmode)