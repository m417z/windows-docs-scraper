# EapHostPeerUninitialize function

## Description

Uninitializes all EAPHost authentication sessions.

The **EapHostPeerUninitialize** function must be called after you are finished calling EAPHost supplicant run-time functions. In addition, if any re-authentication is expected for any reason it is best to call **EapHostPeerUninitialize**.

## Remarks

[EapHostPeerInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerinitialize) and **EapHostPeerUninitialize** are always thread
safe.

**EapHostPeerUninitialize** calls **CoUninitialize**.

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerinitialize)