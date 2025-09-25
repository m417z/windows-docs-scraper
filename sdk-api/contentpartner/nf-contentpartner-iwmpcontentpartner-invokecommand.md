# IWMPContentPartner::InvokeCommand

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **InvokeCommand** method invokes a context menu command.

## Parameters

### `dwCommandID` [in]

ID of the command to invoke. Windows Media Player previously obtained this command ID from the content partner plug-in by calling [IWMPContentPartner::GetCommands](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getcommands).

### `location` [in]

A library location constant that specifies the type of library view where the user right-clicked. For example, the constant g_szCPGenreID specifies that the user right-clicked in the view of a particular genre.

### `pLocationContext` [in]

TheID of the specific view where the user right-clicked. For example, if *location* is g_szCPGenreID, then this parameter is the ID of the particular genre the user was viewing when he or she right-clicked.

### `itemLocation` [in]

A library location constant that specifies the type of the media item or items that were selected when the user right-clicked. For example, the constant g_szCPAlbumID specifies that the user right-clicked when one or more albums were selected.

### `cItemIDs` [in]

The number of items that were selected when the user right-clicked. This is the number of elements in the *rgItemIDs* array.

### `rgItemIDs` [in]

An array that contains the IDs of the media items that were selected when the user right-clicked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)