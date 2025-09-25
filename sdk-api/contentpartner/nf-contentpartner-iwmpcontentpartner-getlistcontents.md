# IWMPContentPartner::GetListContents

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetListContents** method initiates the retrieval of a dynamic list.

## Parameters

### `location` [in]

A library location constant that specifies the type of library view that will have its list retrieved. For example, the constant g_szCPListID specifies that a particular list will be retrieved.

### `pContext` [in]

The ID of the specific item that will have its list retrieved. For example, if *location* is g_szCPListID, then this parameter is the ID of the list that will be retrieved.

### `bstrListType` [in]

A library location constant that specifies the type of an individual list item. For example, the constant g_szCPAlbumID specifies that the items in the list are albums.

### `bstrParams` [in]

Parameters, meaningful only to the online store, associated with the retrieved list. See Remarks.

### `dwListCookie` [in]

A cookie used to identify the list retrieval operation. (The plug-in passes this cookie to [IWMPContentPartnerCallback::AddListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-addlistcontents) and [IWMPContentPartnerCallback::ListContentsComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-listcontentscomplete).)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Retrieving list contents is an asynchronous operation. This method should initiate the retrieval and return immediately. Then the plug-in must make one or more calls to [IWMPContentPartnerCallback::AddListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-addlistcontents) to supply Windows Media Player with the requested list contents. When the plug-in has supplied all the data, it must call [IWMPContentPartnerCallback::ListContentsComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-listcontentscomplete) to signal the end of the operation. In each case, the plug-in passes the cookie provided in *dwListCookie* to identify the correct list retrieval session.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)