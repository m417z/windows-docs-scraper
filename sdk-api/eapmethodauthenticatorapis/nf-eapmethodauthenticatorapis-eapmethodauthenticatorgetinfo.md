# EapMethodAuthenticatorGetInfo function

## Description

Obtains a set of function pointers for an implementation of the loaded EAP authenticator method.**EapMethodAuthenticatorGetInfo** is a function prototype.

## Parameters

### `pEapType` [in]

A pointer to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains the vendor ID of the EAPHost authenticator function implementer.

### `pEapInfo` [out]

A pointer to an [EAP_AUTHENTICATOR_METHOD_ROUTINES](https://learn.microsoft.com/windows/win32/api/eapmethodauthenticatorapis/ns-eapmethodauthenticatorapis-eap_authenticator_method_routines) structure that contains the function pointers to EAP method-specific implementations of the APIs that correspond to specific RPC calls that can be made by EAP peer method functions.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## Remarks

Every EAP authenticator method DLL must have public implementations of the following APIs on it:

* [EapMethodAuthenticatorInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorinitialize)
* [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)
* [EapMethodAuthenticatorUpdateInnerMethodParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorupdateinnermethodparams)
* [EapMethodAuthenticatorReceivePacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorreceivepacket)
* [EapMethodAuthenticatorSendPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsendpacket)
* [EapMethodAuthenticatorGetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetattributes)
* [EapMethodAuthenticatorSetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorsetattributes)
* [EapMethodAuthenticatorGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorgetresult)
* [EapMethodAuthenticatorEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorendsession)
* [EapMethodAuthenticatorShutdown](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorshutdown)

These APIs are called on an EAP authenticator method when an authenticator (server) EAPHost receives a specific corresponding RPC call from a peer (client) EAP method. Note that a complete one-to-one correspondence does not exist between EAP peer methods and EAP authenticator methods; the specific EAP authenticator method API calls should be made based on the requirements of your implementation of the EAP authenticator method API calls.

This call is performed by a authenticator-based EAPHost using a function pointer to this API. This API must be implemented on the EAP authenticator method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)