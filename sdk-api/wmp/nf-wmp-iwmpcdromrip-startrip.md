# IWMPCdromRip::startRip

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **startRip** method rips the CD.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

Ripping a CD by using the **IWMPCdromRip** interface has the same effect as ripping music by using the Windows Media Player user interface. Ripped content is automatically added to the library according to the user's preferences. For more information about user preferences for CD ripping, see "Ripping music from CDs" in Windows Media Player Help.

## See also

[IWMPCdromRip Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromrip)

[IWMPCdromRip::stopRip](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromrip-stoprip)

[Ripping a CD](https://learn.microsoft.com/windows/desktop/WMP/ripping-a-cd)