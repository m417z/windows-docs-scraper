# EapHostPeerFreeEapError function

## Description

Frees [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structures returned by EAPHost run-time APIs.

In contrast, the [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory) function is used only for freeing [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structures returned by EAPHost configuration APIs.

If any of the following run-time APIs are called and an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) is returned, **EapHostPeerFreeEapError** must be called to free the memory:

* [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession)
* [EapHostPeerClearConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerclearconnection)
* [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession)
* [EapHostPeerGetAuthStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetauthstatus)
* [EapHostPeerGetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresponseattributes)
* [EapHostPeerGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresult)
* [EapHostPeerGetSendPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetsendpacket)
* [EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext)
* [EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerprocessreceivedpacket)
* [EapHostPeerSetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeersetresponseattributes)
* [EapHostPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeersetuicontext)

**Note** EAPHost run-time APIs are defined in eappapis.h. EAPHost configuration APIs are defined in EapHostPeerConfigApis.h.

## Parameters

### `pEapError` [in]

A pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains the error data to free.

## Remarks

To release all memory allocated by EAPHost for a authentication session, the caller must call [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession). To release all memory allocated by EAPHost for a connection, the caller must call the [EapHostPeerClearConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerclearconnection) function.

**EapHostPeerFreeEapError** is not thread safe. Any given [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) must be freed on one thread only. Do not call **EapHostPeerFreeEapError** twice on the same **EAP_ERROR** structure.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EAPHost Supplicant Frequently Asked Questions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-supplicant-frequently-asked-questions)

[EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory)