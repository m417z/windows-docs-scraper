# IWMPEvents3::StringCollectionChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **StringCollectionChange** event occurs when a string collection changes.

## Parameters

### `pdispStringCollection` [in]

Pointer to the **IDispatch** interface that represents the string collection that changed. Call **QueryInterface** to retrieve a pointer to **IWMPStringCollection**.

### `change` [in]

[WMPStringCollectionChangeEventType](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpstringcollectionchangeeventtype) value indicating the type of change that occurred.

### `lCollectionIndex` [in]

The index of the string collection item that changed.

## Remarks

To receive **StringCollectionChange** events, you must obtain your string collection as follows:

1. Call [IWMPLibrary::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmplibrary-get_mediacollection) to get an **IWMPMediaCollection** interface.
2. Call the [getAttributeStringCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection-getattributestringcollection) method of the interface you obtained in step 1.

If you obtain your **IWMPMediaCollection** interface by calling [IWMPCore::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_mediacollection), you will not receive **StringCollectionChange** events.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents3)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)