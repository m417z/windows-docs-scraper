# IWMPCore::get_playState

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_playState** method retrieves an enumeration value indicating the operating state of Windows Media Player.

## Parameters

### `pwmpps` [out]

Pointer to a **WMPPlayState** enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player states are not guaranteed to occur in any particular order. Furthermore, not every state necessarily occurs during a sequence of events. You should not write code that relies upon state order.

## See also

[IWMPCore Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcore)

[WMPPlayState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpplaystate)