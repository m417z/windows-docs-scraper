# EOLE_AUTHENTICATION_CAPABILITIES enumeration

## Description

Specifies various capabilities in [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) and [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) (or its helper function [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)).

## Constants

### `EOAC_NONE:0`

Indicates that no capability flags are set.

### `EOAC_MUTUAL_AUTH:0x1`

If this flag is specified, it will be ignored. Support for mutual authentication is automatically provided by some authentication services. See [COM and Security Packages](https://learn.microsoft.com/windows/desktop/com/com-and-security-packages) for more information.

### `EOAC_STATIC_CLOAKING:0x20`

Sets static cloaking. When this flag is set, DCOM uses the thread token (if present) when determining the client's identity. However, the client's identity is determined on the first call on each proxy (if [SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) is not called) and each time [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket) is called on the proxy. For more information about static cloaking, see [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking).

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) and [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) return errors if both cloaking flags are set or if either flag is set when Schannel is the authentication service.

### `EOAC_DYNAMIC_CLOAKING:0x40`

Sets dynamic cloaking. When this flag is set, DCOM uses the thread token (if present) when determining the client's identity. On each call to a proxy, the current thread token is examined to determine whether the client's identity has changed (incurring an additional performance cost) and the client is authenticated again only if necessary. Dynamic cloaking can be set by clients only. For more information about dynamic cloaking, see [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking).

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) and [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) return errors if both cloaking flags are set or if either flag is set when Schannel is the authentication service.

### `EOAC_ANY_AUTHORITY:0x80`

This flag is obsolete.

### `EOAC_MAKE_FULLSIC:0x100`

Causes DCOM to send Schannel server principal names in fullsic format to clients as part of the default security negotiation. The name is extracted from the server certificate. For more information about the fullsic form, see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names).

### `EOAC_DEFAULT:0x800`

Tells DCOM to use the valid capabilities from the call to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity). If **CoInitializeSecurity** was not called, EOAC_NONE will be used for the capabilities flag. This flag can be set only by clients in a call to [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) or [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket).

### `EOAC_SECURE_REFS:0x2`

Authenticates distributed reference count calls to prevent malicious users from releasing objects that are still being used. If this flag is set, which can be done only in a call to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) by the client, the authentication level (in *dwAuthnLevel*) cannot be set to none.

The server always authenticates Release calls. Setting this flag prevents an authenticated client from releasing the objects of another authenticated client. It is recommended that clients always set this flag, although performance is affected because of the overhead associated with the extra security.

### `EOAC_ACCESS_CONTROL:0x4`

Indicates that the *pSecDesc* parameter to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) is a pointer to an [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol) interface on an access control object. When DCOM makes security checks, it calls [IAccessControl::IsAccessAllowed](https://learn.microsoft.com/windows/desktop/api/iaccess/nf-iaccess-iaccesscontrol-isaccessallowed). This flag is set only by the server.

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) returns an error if both the EOAC_APPID and EOAC_ACCESS_CONTROL flags are set.

### `EOAC_APPID:0x8`

Indicates that the *pSecDesc* parameter to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) is a pointer to a GUID that is an AppID. The **CoInitializeSecurity** function looks up the AppID in the registry and reads the security settings from there. If this flag is set, all other parameters to **CoInitializeSecurity** are ignored and must be zero. Only the server can set this flag. For more information about this capability flag, see the Remarks section below.

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) returns an error if both the EOAC_APPID and EOAC_ACCESS_CONTROL flags are set.

### `EOAC_DYNAMIC:0x10`

Reserved.

### `EOAC_REQUIRE_FULLSIC:0x200`

Causes DCOM to fail [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket) calls where an Schannel principal name is specified in any format other than fullsic. This flag is currently for clients only. For more information about the fullsic form, see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names).

### `EOAC_AUTO_IMPERSONATE:0x400`

Reserved.

### `EOAC_DISABLE_AAA:0x1000`

Causes any activation where a server process would be launched under the caller's identity (activate-as-activator) to fail with E_ACCESSDENIED. This value, which can be specified only in a call to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) by the client, allows an application that runs under a privileged account (such as LocalSystem) to help prevent its identity from being used to launch untrusted components.

An activation call that uses CLSCTX_ENABLE_AAA of the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration will allow activate-as-activator activations for that call.

### `EOAC_NO_CUSTOM_MARSHAL:0x2000`

Specifying this flag helps protect server security when using DCOM or COM+. It reduces the chances of executing arbitrary DLLs because it allows the marshaling of only CLSIDs that are implemented in Ole32.dll, ComAdmin.dll, ComSvcs.dll, or Es.dll, or that implement the CATID_MARSHALER category ID. Any service that is critical to system operation should set this flag.

### `EOAC_RESERVED1:0x4000`

## Remarks

When the EOAC_APPID flag is set, [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) looks for the authentication level under the AppID. If the authentication level is not found, it looks for the default authentication level. If the default authentication level is not found, it generates a default authentication level of connect. If the authentication level is not RPC_C_AUTHN_LEVEL_NONE, **CoInitializeSecurity** looks for the access permission value under the AppID. If not found, it looks for the default access permission value. If not found, it generates a default access permission. All the other security settings are determined the same way as for a legacy application.

If the AppID is NULL, **CoInitializeSecurity** looks up the application .exe name in the registry and uses the AppID stored there. If the AppID does not exist, the machine defaults are used.

The [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) method and [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket) function return an error if any of the following flags are set in the capabilities parameter: EOAC_SECURE_REFS, EOAC_ACCESS_CONTROL, EOAC_APPID, EOAC_DYNAMIC, EOAC_REQUIRE_FULLSIC, EOAC_DISABLE_AAA, or EOAC_NO_CUSTOM_MARSHAL.

## See also

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)

[IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket)