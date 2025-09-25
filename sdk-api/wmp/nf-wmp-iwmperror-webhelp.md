# IWMPError::webHelp

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **webHelp** method launches the Windows Media Player Web Help page to display further information about the first error in the error queue (index zero).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The Web Help pages always contain the latest and most detailed information about Windows Media Player errors. This method automatically transfers the other information needed by Web Help, such as the operating system version being used.

To access the Web Help pages directly, use the following error code and support center links.

* [Windows Media Player errors](https://support.microsoft.com/windows/windows-media-player-errors-b3a9ccc1-6267-093e-0aa3-ea860644ecd4)
* [Windows Media Player Solution Center](https://support.microsoft.com/ph/7763#tab0)

**Windows Media Player 10 Mobile:** This method always returns S_OK, but does not launch the Windows Media Player Web Help page.

## See also

[IWMPError Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperror)