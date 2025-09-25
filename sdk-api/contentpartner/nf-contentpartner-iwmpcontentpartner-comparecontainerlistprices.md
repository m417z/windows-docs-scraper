# IWMPContentPartner::CompareContainerListPrices

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **CompareContainerListPrices** method compares the price of two content container lists.

## Parameters

### `pListBase` [in]

Pointer to the **IWMPContentContainerList** interface representing the base content container list.

### `pListCompare` [in]

Pointer to the **IWMPContentContainerList** interface representing the comparison content container list.

### `pResult` [out]

Address of a **long** that receives the result of the comparison. Return less than 0 when the base price is less than the comparison price; return 0 when the base and comparison lists have equal prices; return greater than 0 when the base price is greater than the comparison price.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPContentContainerList Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentcontainerlist)

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)