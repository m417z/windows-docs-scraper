# IWMPDVD::get_domain

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_domain** method retrieves the current domain of the DVD.

## Parameters

### `strDomain` [out]

Pointer to a **BSTR** that contains one of the following values.

| Value | Description |
| --- | --- |
| firstPlay | Performing default initialization of a DVD disc. |
| videoManagerMenu | Displaying menus for the entire disc. Also known as topMenu for Windows Media Player. Commonly called the title menu or the top menu. |
| videoTitleSetMenu | Displaying menus for current title set. Also known as titleMenu for Windows Media Player. Commonly called the root menu. |
| title | Usually displaying the current title. |
| stop | The DVD Navigator is in the DVD Stop domain. |
| undefined | Windows Media Player is not in any DVD domain. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Every DVD is authored differently. Some DVDs do not contain the firstPlay, videoManagerMenu, or videoTitleSetMenu domains.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[IWMPDVD Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpdvd)