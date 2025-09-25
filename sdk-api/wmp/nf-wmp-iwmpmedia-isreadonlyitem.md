# IWMPMedia::isReadOnlyItem

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **isReadOnlyItem** method retrieves a value indicating whether the attributes of the specified media item can be edited.

## Parameters

### `bstrItemName` [in]

**BSTR** containing the item name.

### `pvarfIsReadOnly` [out]

Pointer to a **VARIANT_BOOL** that specifies whether the attributes are read-only.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If an attribute is read-only, then it cannot be set with the **setItemInfo** method. Note that this method may return different values for a particular attribute when used with different versions of Windows Media Player.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **TRUE**.

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia::setItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-setiteminfo)