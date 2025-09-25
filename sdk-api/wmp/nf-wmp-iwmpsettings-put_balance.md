# IWMPSettings::put_balance

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_balance** method specifies the current stereo balance.

## Parameters

### `lBalance` [in]

**long** containing the balance. Values range from –100 to 100. The default value is zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The value zero indicates that the audio plays at equal volume on both left and right channels. A value of –100 indicates that audio plays only on the left channel. A value of 100 indicates that audio plays only on the right channel.

## See also

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::get_balance](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_balance)