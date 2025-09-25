# IWMPPlayer4::get_isRemote

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_isRemote** method retrieves a value indicating whether the Windows Media Player control is running in remote mode.

## Parameters

### `pvarfIsRemote` [out]

Pointer to a **VARIANT_BOOL** indicating whether the Windows Media Player control is running in remote mode. If the value is **TRUE**, then the control is running in remote mode. A value of **FALSE** means the control is running in local mode.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPPlayer4 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer4)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)