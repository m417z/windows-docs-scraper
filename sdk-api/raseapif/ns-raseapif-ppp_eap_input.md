# PPP_EAP_INPUT structure

## Description

The
**PPP_EAP_INPUT** structure is used in the interaction between the RAS Connection Manager Service PPP implementation and the EAP.

This structure provides user information, and facilitates the use of authentication providers, such as a RADIUS server.

## Members

### `dwSizeInBytes`

Specifies the size in bytes of the **PPP_EAP_INPUT** structure. The value of this member can be used to distinguish between current and future versions of this structure.

### `fFlags`

Specifies zero or more of the following flags that qualify the authentication process.

| Value | Meaning |
| --- | --- |
| **RAS_EAP_FLAG_ROUTER** | Specifies whether the computer dialing in is a router or a RAS client. If the computer is a router, this parameter should be set. |
| **RAS_EAP_FLAG_NON_INTERACTIVE** | Specifies that the authentication protocol should not bring up a user-interface. If the authentication protocol is not able to determine the identity from the data supplied, it should return the error code **ERROR_INTERACTIVE_MODE**, which is defined in raserror.h. |
| **RAS_EAP_FLAG_LOGON** | Specifies that the user data from obtained from Winlogon. |
| **RAS_EAP_FLAG_FIRST_LINK** | Indicates that this connection is the first link in a multilink connection. See [Multilink and Callback Connections](https://learn.microsoft.com/windows/win32/eap/multilink-and-callback-connections) for more information. |
| **RAS_EAP_FLAG_GUEST_ACCESS** | Specified if the client wants guest access. This flag is normally used in the case of a wireless connection such that if the authentication fails for N number of consecutive tries the wireless client, if configured to request guest access, then does so by passing this flag. The RADIUS server should be setup to permit guest access. |
| **RAS_EAP_FLAG_8021X_AUTH** | Specifies that this session is executing in a wireless context. |
| **RAS_EAP_FLAG_RESUME_FROM_HIBERNATE** | Specifies that this is the first call after the machine has resumed from hibernation. |
| **RAS_EAP_FLAG_PEAP_UPFRONT** | Specifies that PEAP is enabled at the beginning of the IAS pipeline. |
| **RAS_EAP_FLAG_ALTERNATIVE_USER_DB** | Specifies that the user database is not Active Directory. |
| **RAS_EAP_FLAG_PRE_LOGON** | Specifies that the credentials for the user or a computer account should be obtained in a secure fashion without raising multiple UI instances. |

### `fAuthenticator`

Specifies whether the authentication protocol is operating on the server or client. A value of **TRUE** indicates that the authentication protocol is operating on the server as the authenticator. A value of **FALSE** indicates that the authentication protocol is operating on the client as the process to be authenticated.

### `pwszIdentity`

Pointer to a Unicode string that identifies the user requesting authentication. This string is of the form domain\user or machine\user.

If the authentication protocol is able to derive the user's identity from an additional source, for example a certificate, it should verify that the derived identity matches the value of **pwszIdentity**.

### `pwszPassword`

Pointer to a Unicode string that contains the user's account password. Available only if **fAuthenticator** is **FALSE**. This member may be **NULL**.

### `bInitialId`

Specifies the identifier of the initial EAP packet sent by the DLL. This value is incremented by one for each subsequent request packet.

### `pUserAttributes`

Pointer to an array of
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) structures. The array is terminated by a structure with an **raaType** member that has a value of **raatMinimum** (see
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type)). During the
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)) call, this array contains attributes that describe the currently dialed-in user. When the **fAuthenticationComplete** member is **TRUE**, this array may contain attributes returned by the authentication provider.

### `fAuthenticationComplete`

Specifies a Boolean value that indicates whether the authentication provider has authenticated the user. A value of **TRUE** indicates authentication completion. Check the **dwAuthResultCode** member to determine if the authentication was successful. Ignore this member if the authentication protocol is not using an authentication provider.

### `dwAuthResultCode`

Specifies the result of the authentication provider's authentication process. Successful authentication results in **NO_ERROR**. Authentication failure codes for **dwAuthResultCode** must come only from Winerror.h, Raserror.h or Mprerror.h. Ignore this field if the authentication protocol is not using an authentication provider.

### `hTokenImpersonateUser`

Handle to an impersonation token for the user requesting authentication. This member is valid only on the client side. For more information on impersonation tokens, see [Access Tokens](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens).

### `fSuccessPacketReceived`

Specifies that authentication was successful. RAS sets this member to **TRUE** if the client receives an Network Control Protocol (NCP) packet even though the client has not yet received an EAP success packet. A value of **FALSE** indicates that no NCP packet has been received.

The EAP success packet is a non-acknowledged packet. Therefore, it may be lost and not resent by the server. In this situation, the receipt of an NCP packet indicates that authentication was successful, since the server has moved on to the NCP phase of PPP.

Examine this member only on the client side.

### `fDataReceivedFromInteractiveUI`

Specifies whether information is available from the interactive user interface. Default is **FALSE**. RAS sets this member to **TRUE** whenever the user exits from the authentication protocol's interactive user interface.

### `pDataFromInteractiveUI`

Pointer to data received from the authentication protocol's interactive user interface. This pointer is non-**NULL** if the **fDataReceivedFromInteractiveUI** member is **TRUE** and the interactive user interface did, in fact, return data. Otherwise, this pointer is **NULL**.

If non-**NULL**, the authentication protocol should make a copy of the data in its own memory space. RAS frees the memory occupied by this data on return from the call in which the **PPP_EAP_INPUT** structure was passed. To free the memory, RAS calls the [RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory) function.

### `dwSizeOfDataFromInteractiveUI`

Specifies the size, in bytes, of the data pointed to by **pDataFromInteractiveUI**. If no data is returned from the interactive user interface, this member is zero.

### `pConnectionData`

Pointer to connection data received from the authentication protocol's configuration user interface. This data is available only when the **PPP_EAP_INPUT** structure is passed in [RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)). It is not available in calls to [RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)).

The authentication protocol should make a copy of this data in its own memory space. RAS frees the memory occupied by this data on return from the call in which the **PPP_EAP_INPUT** structure was passed. To free the memory, RAS calls the [RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory) function.

If the authentication protocol's configuration user interface does not return any data, this member is **NULL**.

### `dwSizeOfConnectionData`

Specifies the size in bytes of the data pointed to by **pConnectionData**. If **pConnectionData** is **NULL**, this member is zero.

### `pUserData`

Pointer to user data received from the authentication protocol's [RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity) function on the client computer. If the authentication protocol does not implement **RasEapGetIdentity**, this member points to data from the registry for this user.

This data is available only when the **PPP_EAP_INPUT** structure is passed in [RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)). It is not available in calls to [RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)).

The authentication protocol should make a copy of this data in its own memory space. RAS frees the memory occupied by this data on return from the call in which the **PPP_EAP_INPUT** structure was passed.

If the [RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity) function is not implemented or did not return any data, and no data exists for the user in the registry, this member is **NULL**.

### `dwSizeOfUserData`

Specifies the size, in bytes, of the data pointed to by **pUserData**. If **pUserData** is **NULL**, this member is zero.

### `hReserved`

This member is reserved.

### `guidConnectionId`

### `isVpn`

## Remarks

The **PPP_EAP_INPUT** structure is passed by RAS to the authentication protocol in calls to
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)) and
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)).

The **pwszIdentity** and **pwszPassword** members of the
**PPP_EAP_INPUT** structure are used by the
**RasEapBegin** function to obtain user information. The **pwszPassword** member is non-**NULL** only if the **fAuthenticator** member is **FALSE**, that is, the authentication protocol is running on the client computer.

If the authentication protocol is using an authentication provider, such as Radius or Windows 2000 domain authentication, the following members are used to interface with the authentication provider:

**pUserAttributes**
**fAuthenticationComplete**
**dwAuthResultCode**
Note that the array of
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) structures is passed only if **fAuthenticator** is **TRUE**. This array contains current session information such as port identifier and local IP address.

## See also

[EAP Structures](https://learn.microsoft.com/windows/win32/eap/eap-structures)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute)

[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85))

[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory)

[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))