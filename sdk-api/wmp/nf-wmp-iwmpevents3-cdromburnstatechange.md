# IWMPEvents3::CdromBurnStateChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CdromBurnStateChange** event occurs when a CD burning operation changes state.

## Parameters

### `pCdromBurn` [in]

Pointer to the **IWMPCdromBurn** interface that represents the burning operation that raised the event.

### `wmpbs` [in]

**WMPBurnState** enumeration value that indicates the new state.

## Remarks

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[IWMPEvents3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents3)

[WMPBurnState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpburnstate)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)