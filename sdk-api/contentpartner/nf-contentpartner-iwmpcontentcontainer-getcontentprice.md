# IWMPContentContainer::GetContentPrice

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetContentPrice** method retrieves the price of the media item at the specified index in the content container.

## Parameters

### `idxContent` [in]

Specifies the zero-based index of the media item for which to retrieve the price.

### `pbstrPrice` [out]

Pointer to a **BSTR** that receives the price or one of the following constants.

| String | Description |
| --- | --- |
| g_szContentPrice_Unknown | The price of the content is unknown. |
| g_szContentPrice_CannotBuy | The content cannot be purchased. |
| g_szContentPrice_Free | The content is free. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The format of the string returned in *pbstrPrice* is known only to the online store. Windows Media Player displays, but does not interpret, price strings. For more information about how Windows Media Player and the content partner plug-in exchange price information, see [Purchasing Media Content](https://learn.microsoft.com/windows/desktop/WMP/purchasing-media-content).

## See also

[IWMPContentContainer Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentcontainer)