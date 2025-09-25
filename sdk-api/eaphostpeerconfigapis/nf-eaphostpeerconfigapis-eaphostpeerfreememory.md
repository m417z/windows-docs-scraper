# EapHostPeerFreeMemory function

## Description

 Frees memory returned by the configuration APIs. Do not use this function to free memory allocated to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. Use [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory) to free error memory.

## Parameters

### `pData`

A pointer to the memory to free.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EAPHost Supplicant Frequently Asked Questions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-supplicant-frequently-asked-questions)

[EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory)