# IWMPContentPartnerCallback::SendMessageComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **SendMessageComplete** method notifies Windows Media Player that the online store has finished processing a message.

## Parameters

### `bstrMsg` [in]

**BSTR** containing the message. See Remarks.

### `bstrParam` [in]

**BSTR** containing the message parameters.

### `bstrResult` [in]

**BSTR** containing the result.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **SendMessageComplete** method is part of a chain of methods that are called to pass messages from the discovery page to the content partner plug-in. The following list describes the chain of calls:

1. The discovery page calls [External.sendMessage](https://learn.microsoft.com/windows/desktop/WMP/external-sendmessage), which has two string parameters: *Msg* and *Param*. Those two strings are meaningful only to the online store; they are not interpreted by Windows Media Player.
2. Windows Media Player passes the two strings (*Msg* and *Param*) along to the plug-in by calling [IWMPContentPartner::SendMessage](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-sendmessage).
3. When the online store has finished processing the message, it passes the same two strings back to Windows Media Player by calling **IWMPContentPartnerCallback::SendMessageComplete**. It also passes a third string to **SendMessageComplete** that indicates the result of the message-processing attempt.
4. Windows Media Player passes all three strings back to the discovery page by raising the [External.OnSendMessageComplete](https://learn.microsoft.com/windows/desktop/WMP/external-onsendmessagecomplete-event) event.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)