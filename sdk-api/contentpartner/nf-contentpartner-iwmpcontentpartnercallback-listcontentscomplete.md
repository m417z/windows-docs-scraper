# IWMPContentPartnerCallback::ListContentsComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **ListContentsComplete** method notifies Windows Media Player that the content partner plug-in is finished adding content to a list.

## Parameters

### `dwListCookie` [in]

A cookie that identifies a list retrieval session. Windows Media Player previously supplied this cookie to the content partner plug-in by calling [IWMPContentPartner::GetListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getlistcontents).

### `hrSuccess` [in]

An **HRESULT** that indicates whether the overall transfer of list contents succeeded. Any success code indicates that the transfer succeeded; any error code indicates that the transfer failed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player starts retrieving list contents by calling [IWMPContentPartner::GetListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getlistcontents). This starts an asynchronous operation in which the online store plug-in must call [IWMPContentPartnerCallback::AddListContents](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-addlistcontents) one or more times to give the Player the requested data. The plug-in must finally call **ListContentsComplete** to notify the Player that all the data has been provided.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)