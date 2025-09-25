# WMPTransactionType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPTransactionType** enumeration represents a transaction type.

## Constants

### `wmpttNoTransaction:0`

No transaction.

### `wmpttDownload:1`

A download transaction.

### `wmpttBuy:2`

A purchase transaction.

## See also

[Enumerations for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-1-online-stores)

[IWMPContentContainerList::GetTransactionType](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentcontainerlist-gettransactiontype)