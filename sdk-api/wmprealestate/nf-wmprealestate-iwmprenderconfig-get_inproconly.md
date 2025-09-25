# IWMPRenderConfig::get_inProcOnly

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_inProcOnly** method retrieves a value indicating whether playback is restricted to the current process.

## Parameters

### `pfInProc` [in]

Pointer to a **BOOL** that receives the result. **TRUE** specifies that playback is restricted to the current process.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Using this method with protected content is not supported.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPRenderConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmprealestate/nn-wmprealestate-iwmprenderconfig)