# COSERVERINFO structure

## Description

Identifies a remote computer resource to the activation functions.

## Members

### `dwReserved1`

This member is reserved and must be 0.

### `pwszName`

The name of the computer.

### `pAuthInfo`

A pointer to a [COAUTHINFO](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ns-wtypesbase-coauthinfo) structure to override the default activation security for machine remote activations. Otherwise, set to **NULL** to indicate that default values should be used. For more information, see the Remarks section.

### `dwReserved2`

This member is reserved and must be 0.

## Remarks

The **COSERVERINFO** structure is used primarily to identify a remote system in object creation functions. Computer resources are named using the naming scheme of the network transport. By default, all UNC ("\\*server*" or "*server*") and DNS names ("*domain*.com", "*example*.microsoft.com", or "135.5.33.19") names are allowed.

If **pAuthInfo** is set to **NULL**, [Snego](https://learn.microsoft.com/windows/desktop/com/snego) will be used to negotiate an authentication service that will work between the client and server. However, a non-**NULL**[COAUTHINFO](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ns-wtypesbase-coauthinfo) structure can be specified for **pAuthInfo** to meet any one of the following needs:

* To specify a different client identity for computer remote activations. The specified identity will be used for the launch permission check on the server rather than the real client identity.
* To specify that Kerberos, rather than NTLMSSP, is used for machine remote activation. A nondefault client identity may or may not be specified.
* To request unsecure activation.
* To specify a proprietary authentication service.

If **pAuthInfo** is not **NULL**, those values will be used to specify the authentication settings for the remote call. These settings will be passed to the [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa) function.

If the *pAuthInfo* parameter is **NULL**, then *dwAuthnLevel* can be overridden by the authentication level set by the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) function. If the **CoInitializeSecurity** function isn't called, then the authentication level specified under the [AppID](https://learn.microsoft.com/windows/desktop/com/appid-key) registry key is used, if it exists.

Starting with Windows XP with Service Pack 2 (SP2), *dwAuthnLevel* is the maximum of RPC_C_AUTHN_LEVEL_CONNECT and the process-wide authentication level of the client process that is issuing the activation request. For earlier versions of the operating system, this is RPC_C_AUTHN_LEVEL_CONNECT.

## See also

[Activation Security](https://learn.microsoft.com/windows/desktop/com/activation-security)

[COAUTHINFO](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ns-wtypesbase-coauthinfo)

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoGetInstanceFromFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromfile)

[CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage)

[Turning Off Activation Security](https://learn.microsoft.com/windows/desktop/com/turning-off-activation-security)