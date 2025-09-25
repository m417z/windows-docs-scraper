# EapPeerInitialize function

## Description

Initializes an EAP peer method for EAPHost.

## Parameters

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

 An EAP method is a DLL that implements and exports the EAP Peer Method APIs. Example methods include MS-PEAPv0 and later, MS-EAP-TLS, and MS-CHAPv2. You can also create and implement custom EAP methods, as well.

The EAP method libraries together with EAPHOST.dll make up the "EAPHost". The host DLL manages the libraries and allows supplicants (EAP clients) to authenticate against them.

Each API is handled as a function pointer by EAPHost, who calls them if they conform to the specific signatures and calling conventions specified in this documentation. These function pointers are obtained when EAPHost calls [EapPeerGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetinfo).

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)