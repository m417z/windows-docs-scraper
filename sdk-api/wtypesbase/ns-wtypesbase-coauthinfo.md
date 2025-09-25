# COAUTHINFO structure

## Description

Contains the authentication settings used while making a remote activation request from the client computer to the server computer.

## Members

### `dwAuthnSvc`

The authentication service to be used. For a list of values, see [Authentication Service Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). Use RPC_C_AUTHN_NONE if no authentication is required. RPC_C_AUTHN_WINNT is the default and RPC_C_AUTHN_GSS_KERBEROS is also supported.

### `dwAuthzSvc`

The authorization service to be used. For a list of values, see [Authorization Constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). To use the NT authentication service, specify RPC_C_AUTHZ_NONE.

### `pwszServerPrincName`

The server principal name to use with the authentication service. If you are using RPC_C_AUTHN_WINNT, the principal name must be **NULL**.

### `dwAuthnLevel`

The authentication level to be used. For a list of values, see [Authentication Level Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants).

As of Windows Server 2003, remote activations use the default authentication level specified in the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) *dwAuthnLevel* parameter. In previous versions of Windows, RPC_C_AUTHN_LEVEL_CONNECT was always used for the security level unless another level was explicitly specified.

### `dwImpersonationLevel`

The impersonation level to be used. For a list of values, see [Impersonation Level Constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). This value must be RPC_C_IMP_LEVEL_IMPERSONATE or above.

### `pAuthIdentityData`

A pointer to a [COAUTHIDENTITY](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ns-wtypesbase-coauthidentity) structure that establishes a nondefault client identity. If this parameter is **NULL**, the actual identity of the client is used. Values of structure members are authentication-service specific. This value must be **NULL** if **dwAuthnSvc** does not specify either the NTLMSSP or Kerberos network authentication protocol is used as the authorization service.

### `dwCapabilities`

Indicates additional capabilities of this proxy. Currently, this member must be EOAC_NONE (0x0) or RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH (0x1). Use RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH if Kerberos is required.

## Remarks

If **pAuthInfo** in [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) is set to **NULL**, Snego will be used to negotiate an authentication service that will work between the client and server. However, a non-**NULL****COAUTHINFO** structure can be specified for **pAuthInfo** to meet any one of the following needs:

* To specify a different client identity for computer remote activations. The specified identity will be used for the launch permission check on the server rather than the real client identity.
* To specify that Kerberos, rather than NTLMSSP, is used for machine remote activation. A nondefault client identity may or may not be specified.
* To request unsecure activation.
* To specify a proprietary authentication service.

Specifying a **COAUTHINFO** structure allows DCOM activations to work correctly with security providers other than NTLMSSP. You can also specify additional security information used during remote activations for interoperability with alternate implementations of DCOM.

If you set **dwAuthzSvc**, **pwszServerPrincName**, **dwImpersonationLevel**, or **dwCapabilities** to incorrect values and call either [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) or [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex), these functions do not return E_INVALIDARG or a similar error. Default values are used instead of the incorrect values.

## See also

[COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo)