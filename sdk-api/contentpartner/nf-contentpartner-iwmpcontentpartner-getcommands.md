# IWMPContentPartner::GetCommands

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetCommands** method retrieves context menu commands.

## Parameters

### `location` [in]

A [library location constant](https://learn.microsoft.com/windows/desktop/WMP/library-location-constants) that specifies the type of library view where the user right-clicked. For example, the constant g_szCPGenreID indicates that the user right-clicked in the view of a particular genre

### `pLocationContext` [in]

The ID of the specific view where the user right-clicked. For example, if *location* is g_szCPGenreID, this parameter is the ID of the particular genre the user was viewing when he or she right-clicked.

### `itemLocation` [in]

A library location constant that indicates the type of the media item or items that were selected when the user right-clicked. For example, the constant g_szCPAlbumID specifies that the user right-clicked when one or more albums were selected.

### `cItemIDs` [in]

The number of items that were selected when the user right-clicked. This is the number of elements in the *prgItemIDs* array.

### `prgItemIDs` [in]

An array that contains the IDs of the media items that were selected when the user right-clicked.

### `pcItemIDs` [out]

The number of elements in the *pprgItems* array.

### `pprgItems` [out]

Address of a variable that receives a pointer to an array of [WMPContextMenuInfo](https://learn.microsoft.com/windows/desktop/api/contentpartner/ns-contentpartner-wmpcontextmenuinfo) structures.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method must call **CoTaskMemAlloc** to allocate the array that it returns in *pprgItems*.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)