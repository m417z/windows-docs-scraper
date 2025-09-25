# IWMPContentPartnerCallback::AddListContents

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **AddListContents** method adds a set of media items to a list.

## Parameters

### `dwListCookie` [in]

A cookie that identifies a list retrieval session. Windows Media Player previously supplied this cookie to the content partner plug-in by calling [IWMPContentPartner::GetListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getlistcontents).

### `cItems` [in]

Count of items to be added to the list. This is the number of elements in the *prgItems* array.

### `prgItems` [in]

Pointer to an array of media item IDs. These are the IDs of the media items that are to be added to the list.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)