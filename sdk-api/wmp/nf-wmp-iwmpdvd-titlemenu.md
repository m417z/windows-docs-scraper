# IWMPDVD::titleMenu

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **titleMenu** method stops playback and displays the title menu.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Every DVD is authored differently. The DVD must contain a menu for this method to work. Some DVDs are authored so that the **IWMPDVD::topMenu** and **titleMenu** methods open the same menu. The **titleMenu** method usually invokes the title menu, but it may invoke the top menu if there is no title menu available.

**Windows Media Player 10 Mobile:** This method always returns S_OK, but does not perform the intended operation.

## See also

[IWMPDVD Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpdvd)

[IWMPDVD::topMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpdvd-topmenu)