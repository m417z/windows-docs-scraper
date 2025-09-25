# EapHostPeerFreeErrorMemory function

## Description

Frees memory allocated to an [EAPHost supplicant configuration function](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions) fails.

The **EapHostPeerFreeErrorMemory** function is used only for freeing [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structures returned by EAPHost configuration APIs, while the [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror) function is used for freeing **EAP_ERROR** structures returned by EAPHost run-time APIs.

If any of the following configuration APIs functions are called, and an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) is returned, **EapHostPeerFreeErrorMemory** must be called to free the memory:

* [EapHostPeerConfigBlob2Xml](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerconfigblob2xml)
* [EapHostPeerConfigXml2Blob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerconfigxml2blob)
* [EapHostPeerCredentialsXml2Blob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeercredentialsxml2blob)
* [EapHostPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeconfigui)
* [EapHostPeerQueryCredentialsInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerquerycredentialinputfields)
* [EapHostPeerQueryUserBlobFromCredentialsInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryuserblobfromcredentialinputfields)

**Note** EAPHost run-time APIs are defined in eappapis.h. EAPHost configuration APIs are defined in EapHostPeerConfigApis.h.

## Parameters

### `pEapError`

A pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains the error data to free.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EAPHost Supplicant Frequently Asked Questions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-supplicant-frequently-asked-questions)

[EapHostFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror)