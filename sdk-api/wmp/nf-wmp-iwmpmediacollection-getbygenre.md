# IWMPMediaCollection::getByGenre

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getByGenre** method retrieves a pointer to an **IWMPPlaylist** interface. This interface contains the media items with the specified genre.

## Parameters

### `bstrGenre` [in]

String containing the genre.

### `ppMediaItems` [out]

Pointer to a pointer to an **IWMPPlaylist** interface for the retrieved media items.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

There are two ways you ways you can retrieve an **IWMPMediaCollection** interface, and the behavior of the **getByGenre** method depends on which of those two ways you use. If you retrieve the interface by calling [IWMPCore::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_mediacollection), then the **getByGenre** method returns all the media items in the library that belong to the specified genre. If you retrieve the interface by calling [IWMPLibrary::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmplibrary-get_mediacollection), then the **getByGenre** method returns only the audio items in the library that belong to the specified genre.

## See also

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)