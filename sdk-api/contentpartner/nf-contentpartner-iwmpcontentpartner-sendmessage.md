# IWMPContentPartner::SendMessage

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **SendMessage** method enables discovery pages to send messages to the plug-in.

## Parameters

### `bstrMsg` [in]

**BSTR** containing the message.

### `bstrParam` [in]

**BSTR** containing the message parameters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The plug-in must call [IWMPContentPartnerCallback::SendMessageComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-sendmessagecomplete) to notify Windows Media Player that the message has been processed. This causes the [OnSendMessageComplete](https://learn.microsoft.com/windows/desktop/WMP/external-onsendmessagecomplete-event) event to occur in the discovery page.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)