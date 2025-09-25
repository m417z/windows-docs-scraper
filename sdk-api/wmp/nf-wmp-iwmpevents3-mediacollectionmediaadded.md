# IWMPEvents3::MediaCollectionMediaAdded

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MediaCollectionMediaAdded** event occurs when a media item is added to the local library.

## Parameters

### `pdispMedia` [in]

Pointer to the **IDispatch** interface that represents the media item added to the local library. Call **QueryInterface** to retrieve a pointer to **IWMPMedia**.

## Remarks

This event occurs only for the local library.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents3)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)