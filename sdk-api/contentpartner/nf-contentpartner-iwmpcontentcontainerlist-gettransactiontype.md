# IWMPContentContainerList::GetTransactionType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetTransactionType** method retrieves the type of the current transaction.

## Parameters

### `pwmptt` [out]

Pointer to a [WMPTransactionType](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmptransactiontype) that receives the transaction type value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPContentContainerList Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentcontainerlist)

[WMPTransactionType](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmptransactiontype)