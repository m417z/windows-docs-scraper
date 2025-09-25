# EapHostPeerGetDataToUnplumbCredentials function

## Description

Returns the **Connection Id**,**User Impersonation Token** and **Eaphost Process Id**  used by EAPHost to save the credentials for SSO. This data is needed to unplumb previously plumbed credentials.

**Important**
Unplumbing of credentials (plumbed as part of the SSO experience) on disconnection is no longer performed by EAPHost. Unplumbing of credentials now needs to be performed by the supplicant.

## Parameters

### `pConnectionIdThatLastSavedCreds` [out]

The GUID of the EAP peer session that last plumbed credentials.

### `phCredentialImpersonationToken` [out]

Handle to impersonate the user at the time of plumbing credentials. The user can be impersonated by a call to **ImpersonateLoggedOnUser**.

### `sessionHandle` [out]

A pseudo handle to the EAPHost process. This is the __int3264 value returned to EAPHost when it called [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess).

### `ppEapError` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `fSaveToCredMan` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession)

[EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession)