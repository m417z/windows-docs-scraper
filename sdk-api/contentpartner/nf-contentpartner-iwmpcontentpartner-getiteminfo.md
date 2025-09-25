# IWMPContentPartner::GetItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetItemInfo** method retrieves information (for example, a URL or a caption) related to an item owned by an online store.

## Parameters

### `bstrInfoName` [in]

**BSTR** specifying the item for which information will be retrieved. See Remarks for possible values.

### `pContext` [in]

Pointer to a **VARIANT** that supplies contextual information for the requested information.

### `pData` [out]

Pointer to a **VARIANT** that receives the information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following list gives possible values for the *bstrInfoName* parameter and corresponding values for the *pContext* and *pData* parameters.

g_szItemInfo_AlbumArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of an album in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the album.

g_szItemInfo_ALTLoginURL

The *pContext* parameter has type **VT_EMPTY** and supplies no information.

The *pData* parameter receives a **VT_BSTR** that is the URL of a webpage that Windows Media Player will display as an alternative to the standard log-in dialog box. Windows Media Player requests the alternative log-in URL only if the **SUBSCRIPTION_CAP_ALTLOGIN** flag is set in the **Capabilities** registry entry for the online store's plug-in. For more information about the **Capabilities** registry entry, see [Registry Keys and Entries for a Type 1 Online Store](https://learn.microsoft.com/windows/desktop/WMP/registry-keys-and-entries-for-a-type-1-online-store).

The online store can specify the size of the window that hosts the alternative log-in page by appending the parameter string ?DlgX=*width*&DlgY=*height* to the URL. In the parameter string, *width* and *height* are the width and height of the window in pixels. For example **GetItemInfo** could return the following string to specify that AltLogin.htm should be displayed in a window that has a width of 800 pixels and a height of 400 pixels:

http://proseware.com/AltLogin.htm?DlgX=800&DlgY=400

g_szItemInfo_ALTLoginCaption

The *pContext* parameter has type **VT_EMPTY** and supplies no information.

The *pData* parameter receives a **VT_BSTR** that is the caption for the window that Windows Media Player will open to host the alternative log-in webpage.

g_szItemInfo_ArtistArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of an artist in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the artist.

g_szItemInfo_AuthenticationSuccessURL

The *pContext* parameter supplies a **VT_I4** that is the index of a webpage, provided by the online store, that Windows Media Player will display after successful authentication.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage. Note that indexes for webpages that represent authentication success are not interpreted by Windows Media Player; they have meaning only to the online store.

g_szItemInfo_ErrorDescription

The *pContext* parameter supplies a **VT_ERROR** that is an **HRESULT** that the plug-in previously supplied to the Player. For example, the plug-in supplies an **HRESULT** when it calls [IWMPContentPartnerCallback::BuyComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-buycomplete).

The *pData* parameter receives a **VT_BSTR** that is the error description created by the online store and associated with the **HRESULT**. Windows Media Player displays the error message but does not interpret it.

g_szItemInfo_ErrorURL

The *pContext* parameter supplies a **VT_ERROR** that is an **HRESULT** that the plug-in previously supplied to the Player. For example, the plug-in supplies an **HRESULT** when it calls **IWMPContentPartnerCallback::BuyComplete**.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage that Windows Media Player will display when the user clicks the error-resolving link. The error-resolving link is part of the user interface of the Player.

g_szItemInfo_ErrorURLLinkText

The *pContext* parameter supplies a **VT_ERROR** that is an **HRESULT** that the plug-in previously supplied to the Player. For example, the plug-in supplies an **HRESULT** when it calls **IWMPContentPartnerCallback::BuyComplete**.

The *pData* parameter receives a **VT_BSTR** that is the text, created by the online store, that Windows Media Player will use when it displays the error-resolving link.

g_szItemInfo_TreeListIconURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of a list in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the icon that Windows Media Player will display, in the tree-view control, for the list.

g_szItemInfo_CreateAccountURL

The *pContext* parameter has type **VT_EMPTY** and supplies no information.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage that Windows Media Player will display to enable the user to manage his or her account.

g_szItemInfo_ForgetPasswordURL

The *pContext* parameter has type **VT_EMPTY** and supplies no information.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage that Windows Media Player will display when the user forgets his or her password.

g_szItemInfo_GenreArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of a genre in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the genre.

g_szItemInfo_HTMLViewURL

The *pContext* parameter supplies a **VT_BSTR** that is a string that Windows Media Player obtained from a [PARAM](https://learn.microsoft.com/windows/desktop/WMP/param-element) element in a Windows Media metafile (ASX file).

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage that Windows Media Player will display.

When the **name** attribute of a **PARAM** element is "HTMLFlink", Windows Media Player passes the **value** attribute of the PARAM element to this method to retrieve the URL of a Web Page to display in the **Now Playing** feature.

g_szItemInfo_ListArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of a list in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the list.

g_szItemInfo_LoginFailureURL

The *pContext* parameter supplies a **VT_UI4** that is the index of a webpage, provided by the online store, that Windows Media Player will display after a log-in failure.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage.

Windows Media Player previously obtained the index when the online store's plug-in called [IWMPContentPartnerCallback::Notify](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-notify), passing wmpcnLoginStateChange in the *type* parameter. The indexes of log-in failure webpages are not interpreted by Windows Media Player; they have meaning only to the online store.

g_szItemInfo_PopupURL

The *pContext* parameter supplies a **VT_I4** that is the index of a pop-up webpage, provided by the online store, that Windows Media Player will display in a modal window.

The *pData* parameter receives a **VT_BSTR** that is the URL of the webpage to display in the modal window. Indexes of pop-up webpages are not interpreted by Windows Media Player; they have meaning only to the online store.

g_szItemInfo_PopupCaption

The *pContext* parameter supplies a **VT_I4** that is the index of a pop-up caption created by the online store.

The *pData* parameter receives a **VT_BSTR** that is the caption for the window that Windows Media Player will open to host the pop-up webpage. Pop-up caption indexes are not interpreted by Windows Media Player; they have meaning only to the online store.

g_szItemInfo_RadioArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of a radio feed in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the radio feed.

g_szItemInfo_SubGenreArtURL

The *pContext* parameter supplies a **VT_UI4** that is the ID of a subgenre in the online store's catalog.

The *pData* parameter receives a **VT_BSTR** that is the URL of the art that Windows Media Player will display for the subgenre.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)