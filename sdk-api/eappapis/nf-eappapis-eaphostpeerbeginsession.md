# EapHostPeerBeginSession function

## Description

Starts an EAP authentication session.
If the **EapHostPeerBeginSession** function succeeds, the caller must also call [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession) to end the authentication session. The latter function must be called regardless of whether functions other than **EapHostPeerBeginSession** succeed or fail.

If re-authentication is required, regardless of the reason, the interface represented by the parameter *pConnectionId* will be unregistered. In cases where *pConnectionId* is unregistered, you must also call [EapHostPeerClearConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerclearconnection) to remove the connection.

Never call **EapHostPeerBeginSession** again on an interface without calling [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession). Only one authentication session can be active on the interface specified by *pConnectionId*.

## Parameters

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the new EAP authentication session behavior.

### `eapType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the type of EAP authentication to use for this session.

### `pAttributeArray` [in]

Pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that specifies the EAP attributes of the entity to authenticate.

### `hTokenImpersonateUser` [in]

Handle to the user impersonation token to use in this session.

### `dwSizeofConnectionData` [in]

The size, in bytes, of the connection data buffer provided in *pConnectionData*.

### `pConnectionData` [in]

Describes the configuration used for authentication. **NULL** connection data is considered valid. The method should work with the default configuration.

### `dwSizeofUserData` [in]

The size, in bytes, of the user data buffer provided in *pUserData*.

### `pUserData` [in]

A pointer to a byte buffer that contains the opaque user data BLOB containing user data returned from the [EapPeerGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetidentity) function. User data may include credentials or certificates used for authentication. *pUserData* can be **NULL**. The interpretation of a **NULL** pointer depends on the implementation of a method. The user data consists of user or machine credentials used for authentication. Typically the user data depends on the configuration data.

If **EAP_FLAG_PREFER_ALT_CREDENTIALS** is indicated in *dwflags*, then credentials passed into [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession) are preferred to all other forms of credential retrieval, even if configuration data passed into *pConnectionData* requests a different mode of credential retrieval. If passing credentials into **EapPeerBeginSession** fails, then EAPHost resorts to method specific credential retrieval, in which case credentials could be obtained from a file, Windows login, or a certificate store, for example.

The EAP method author defines both the default credentials and alternate credentials. For example, in the case of EAP-MSCHAPv2 the default credentials are Windows credentials obtained from winlogon, and alternate credentials are the credentials (user name, password, domain) passed into *pUserData*.

### `dwMaxSendPacketSize` [in]

The maximum size, in bytes, of an EAP packet that can be sent during the session.

### `pConnectionId` [in]

A pointer to a GUID value that uniquely identifies the logical network interface over which the authentication of the supplicant will take place. If the supplicant seeks re-authentication after a NAP health change, it should provide a unique GUID.
The parameter should be **NULL** when this function is called by a tunneling method to start its inner method. When the *pConnectionId* parameter is **NULL**, the *func* and *pContextData* parameters are ignored.

### `func` [in]

A [NotificationHandler](https://learn.microsoft.com/windows/desktop/api/eappapis/nc-eappapis-notificationhandler) function pointer that provides the callback used by EAPHost to notify the supplicant when re-authentication is needed.

If the function handler is **NULL**, the *pContextData* parameter is ignored. If the function handler is **NULL**, it also means that the caller is not interested in SoH change notification
from the EAP quarantine enforcement client (QEC).

The following code shows a [NotificationHandler](https://learn.microsoft.com/windows/desktop/api/eappapis/nc-eappapis-notificationhandler) callback call.

``` syntax
func(*pConnectionId, pContextData);
```

### `pContextData` [in]

A pointer to re-authentication context data that the supplicant will associate with the connection when *func* is called. This parameter can be **NULL**.

### `pSessionId` [out]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## Remarks

If an EAPHost supplicant is participating in NAP, the supplicant will respond to changes in the state of its network health. If that state changes, the supplicant must then initiate a re-authentication session as follows.

* If there is a current session when re-authentication occurs, the supplicant should tear down the current session by calling [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession), and then start a new session by calling **EapHostPeerBeginSession**.
* If there is no current session with re-authentication occurs, or the previous session was already ended by calling [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession), the supplicant only needs to start a new session by calling **EapHostPeerBeginSession**.

The call to **EapHostPeerBeginSession** to establish the re-authentication session can be made from the callback specified in the *func* parameter and called when the health state changes. This callback function indicates to the supplicant to tear down the network authentication associated with the GUID and re-authenticate.

A connection can be kept across multiple sessions because **EapHostPeerBeginSession** can provide a valid GUID to register the connection. When [EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession) is called, only the current session is terminated. Because the registration with the GUID isn't terminated, the original registration by **EapHostPeerBeginSession** remains intact. Therefore, the registration is effective across multiple sessions.

**Note** Registering the connection refers to providing a valid GUID and valid callback function pointer.

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerClearConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerclearconnection)

[EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)