# IWMPCdromBurn::get_burnState

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_burnState** method retrieves an enumeration value that indicates the current burn state.

## Parameters

### `pwmpbs` [out]

Pointer to a variable that receives a value from the **WMPBurnState** enumeration that indicates the current state.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[WMPBurnState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpburnstate)