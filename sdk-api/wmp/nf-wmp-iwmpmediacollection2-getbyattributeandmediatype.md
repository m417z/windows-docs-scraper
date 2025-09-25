# IWMPMediaCollection2::getByAttributeAndMediaType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getByAttributeAndMediaType** method retrieves a pointer to an **IWMPPlaylist** interface. This interface represents a playlist that contains media items that have a specified attribute and media type.

## Parameters

### `bstrAttribute` [in]

String that contains the specified attribute.

### `bstrValue` [in]

String that contains the specified value for the attribute that is specified in *bstrAttribute*.

### `bstrMediaType` [in]

String that contains the specified media type.

### `ppMediaItems` [out]

Address of a variable that receives a pointer to an **IWMPPlaylist** interface for the retrieved playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPMediaCollection2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection2)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)