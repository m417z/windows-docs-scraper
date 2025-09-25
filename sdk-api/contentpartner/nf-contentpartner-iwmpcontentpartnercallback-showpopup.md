# IWMPContentPartnerCallback::ShowPopup

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **ShowPopup** method instructs Windows Media Player to display an HTML-based dialog box that hosts a webpage provided by the online store.

## Parameters

### `lIndex` [in]

Index, meaningful only to the online store, of the webpage to display in the dialog box.

### `bstrParameters` [in]

Parameters associated with the dialog box.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player calls [IWMPContentPartner::GetItemInfo](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getiteminfo), passing the value of *lIndex* in the *pContext* parameter, to retrieve a URL. Windows Media Player then appends the value of *bstrParameters* to the URL, and uses the URL, along with the appended parameters, to retrieve the webpage to display in the dialog box.

You can use the *bstrParameters* parameter to specify the size of the pop-up window. For example, if you set *bstrParameters* to "DlgX=800&DlgY=400", the pop-up window will have a size of 800 pixels by 400 pixels.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)