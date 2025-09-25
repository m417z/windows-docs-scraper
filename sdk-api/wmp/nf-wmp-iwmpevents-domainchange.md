# IWMPEvents::DomainChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DomainChange** event occurs when the DVD domain changes.

## Parameters

### `strDomain` [in]

Specifies the new domain. It can be one of the following values:

| String | Description |
| --- | --- |
| firstPlay | Performing default initialization of a DVD disc. |
| videoManagerMenu | Displaying menus for whole disc. Also known as Root Menu or topMenu. |
| videoTitleSetMenu | Displaying menus for current title set. Also known as titleMenu |
| title | Displaying the current title. |
| stop | The DVD Navigator is in the DVD Stop domain. |

## Remarks

**Windows Media Player 10 Mobile:** This event is not supported.

Windows XP or later.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)