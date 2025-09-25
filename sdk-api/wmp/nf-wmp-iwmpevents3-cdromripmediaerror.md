# IWMPEvents3::CdromRipMediaError

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CdromRipMediaError** event occurs when an error happens while ripping an individual track from a CD.

## Parameters

### `pCdromRip` [in]

Pointer to the **IWMPCdromRip** interface that represents the ripping operation that raised the error.

### `pMedia` [in]

Pointer to the **IDispatch** interface that represents the media item that raised the error. Call **QueryInterface** through this pointer to retrieve a pointer to **IWMPMedia**.

## Remarks

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPCdromRip Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromrip)

[IWMPEvents3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents3)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)