# PPP_EAP_OUTPUT structure

## Description

The authentication protocol uses the
**PPP_EAP_OUTPUT** structure to communicate requests and status information to the Connection Manager on return from calls to
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)).

## Members

### `dwSizeInBytes`

Specifies the size of this structure.

### `Action`

Specifies a
[PPP_EAP_ACTION](https://learn.microsoft.com/windows/desktop/api/raseapif/ne-raseapif-ppp_eap_action) value. The Connection Manager carries out this action on behalf of the authentication protocol.

### `dwAuthResultCode`

Specifies whether authentication was successful. Any nonzero value for **dwAuthResultCode** indicates failure. The failure code must come from Winerror.h, Raserror.h or Mprerror.h. This member is valid only if the **Action** member has a value of **EAPACTION_Done** or **EAPACTION_SendAndDone**.

### `pUserAttributes`

Pointer to an optional array of
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) structures. The array is terminated by a structure with an **raaType** member that has a value of **raatMinimum** (see
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type)).

This member should be set on the authenticator side when **Action** is **EAPACTION_Authenticate**, or when **Action** is **EAPACTION_Done** or **EAPACTION_SendAndDone** and **dwAuthResultCode** is zero.

When **Action** is **EAPACTION_Authenticate**, the array may contain additional attributes necessary to authenticate the user, e.g. the user-password. If the authentication protocol passes in only the user name, RAS does not invoke the authentication provider to authenticate the user, Instead, RAS just passes back the current attributes for the user.

When **Action** is **EAPACTION_Done** or **EAPACTION_SendAndDone**, and **dwAuthResultCode** is zero, the array may contain additional attributes to assign to the user. These attributes overwrite any attributes of the same type returned by the authentication provider.

The authentication protocol frees this memory in its
[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85)) function.

### `fInvokeInteractiveUI`

Specifies whether RAS should invoke the authentication protocol's interactive UI. If the authentication protocol sets this member to **TRUE**, RAS invokes the interactive UI, by calling the
[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui) function provided by the authentication protocol.

### `pUIContextData`

Pointer to context data that RAS should pass in the call to
[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui). The authentication protocol should free this memory in its implementation of
[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85)).

### `dwSizeOfUIContextData`

Specifies the size of the context data that RAS should pass in the call to
[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui).

### `fSaveConnectionData`

Specifies whether RAS should save the information pointed to by the **pConnectionData** member. If **fSaveConnectionData** is **TRUE**, RAS will save the data in the phone book. Only valid for the process that is being authenticated.

### `pConnectionData`

Identifies data specific to the connection, that is, data not specific to any particular user. If the **fSaveConnectionData** member is **TRUE**, RAS saves the connection data in the phone book. The authentication protocol should free the memory occupied by this data during the call to
[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85)).

### `dwSizeOfConnectionData`

Specifies the size, in bytes, of the data pointed to by the **pConnectionData** member.

### `fSaveUserData`

Specifies whether RAS should save the user data pointed to by the **pUserData** member. If this parameter is **TRUE**, RAS saves the user-specific data in the registry under **HKEY_CURRENT_USER**.

### `pUserData`

Pointer to user data that RAS should save in the registry. RAS saves this data in the registry under **HKEY_CURRENT_USER**. The authentication protocol should free this memory during the call to
[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85)).

### `dwSizeOfUserData`

Specifies the size in bytes of the data pointed to by **pUserData**.

### `pNgcKerbTicket`

### `fSaveToCredMan`

## Remarks

Use the
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)) function to pass the
**PPP_EAP_OUTPUT** structure between the authentication protocol and the Connection Manager.

The authentication protocol can use the
**PPP_EAP_OUTPUT** structure to return the Microsoft Point-to-Point Encryption (MPPE) session keys. The authentication protocol must place the session keys in the value field of a sub-attribute contained within the value field of an attribute of type **raatVendorSpecific** (see
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type)). The sub-attribute should have a Vendor-ID of 311 (Microsoft) and Vendor-Type of MS-MPPE-Recv-Keys (17) and MS-MPPE-Send-Keys (16). The authentication protocol must set the **pUserAttributes** member to point to the **raatVendorSpecific** attribute, and set the **Action** member to **EAPACTION_Done** or **EAPACTION_SendAndDone**. For more information about the format of the MPPE sub-attribute see
[Microsoft Vendor-specific RADIUS Attributes](https://www.ietf.org/rfc/rfc2548.txt). For more information about attribute formats see
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute),
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type), and
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

**Note** When formatting attributes for encryption keys, it is strongly recommended that you use MSCHAPv2 and its MS-MPPE-Recv-Keys and MS-MPPE-Send-Keys, which create *strong encryption* rather than MSCHAPv1 and its MS-CHAP-MPPE-Keys.

## See also

[EAP Structures](https://learn.microsoft.com/windows/win32/eap/eap-structures)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[PPP_EAP_ACTION](https://learn.microsoft.com/windows/desktop/api/raseapif/ne-raseapif-ppp_eap_action)

[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute)

[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))