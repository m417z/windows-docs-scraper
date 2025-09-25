# CoInitializeSecurity function

## Description

Registers security and sets the default security values for the process.

## Parameters

### `pSecDesc` [in, optional]

The access permissions that a server will use to receive calls. This parameter is used by COM only when a server calls **CoInitializeSecurity**. Its value is a pointer to one of three types: an AppID, an [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol) object, or a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor), in absolute format. See the Remarks section for more information.

### `cAuthSvc` [in]

The count of entries in the *asAuthSvc* parameter. This parameter is used by COM only when a server calls **CoInitializeSecurity**. If this parameter is 0, no authentication services will be registered and the server cannot receive secure calls. A value of -1 tells COM to choose which authentication services to register, and if this is the case, the *asAuthSvc* parameter must be **NULL**. However, Schannel will never be chosen as an authentication service by the server if this parameter is -1.

### `asAuthSvc` [in, optional]

An array of authentication services that a server is willing to use to receive a call. This parameter is used by COM only when a server calls **CoInitializeSecurity**. For more information, see [SOLE_AUTHENTICATION_SERVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_service).

### `pReserved1` [in, optional]

This parameter is reserved and must be **NULL**.

### `dwAuthnLevel` [in]

The default authentication level for the process. Both servers and clients use this parameter when they call **CoInitializeSecurity**. COM will fail calls that arrive with a lower authentication level. By default, all proxies will use at least this authentication level. This value should contain one of the [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). By default, all calls to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) are made at this level.

### `dwImpLevel` [in]

The default impersonation level for proxies. The value of this parameter is used only when the process is a client. It should be a value from the [impersonation level constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants), except for RPC_C_IMP_LEVEL_DEFAULT, which is not for use with **CoInitializeSecurity**.

Outgoing calls from the client always use the impersonation level as specified. (It is not negotiated.) Incoming calls to the client can be at any impersonation level. By default, all [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) calls are made with this impersonation level, so even security-aware applications should set this level carefully. To determine which impersonation levels each authentication service supports, see the description of the authentication services in [COM and Security Packages](https://learn.microsoft.com/windows/desktop/com/com-and-security-packages). For more information about impersonation levels, see [Impersonation](https://learn.microsoft.com/windows/desktop/com/impersonation).

### `pAuthList` [in, optional]

A pointer to [SOLE_AUTHENTICATION_LIST](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_list), which is an array of [SOLE_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_info) structures. This list indicates the information for each authentication service that a client can use to call a server. This parameter is used by COM only when a client calls **CoInitializeSecurity**.

### `dwCapabilities` [in]

Additional capabilities of the client or server, specified by setting one or more [EOLE_AUTHENTICATION_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-eole_authentication_capabilities) values. Some of these value cannot be used simultaneously, and some cannot be set when particular authentication services are being used. For more information about these flags, see the Remarks section.

### `pReserved3` [in, optional]

This parameter is reserved and must be **NULL**.

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **RPC_E_TOO_LATE** | [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) has already been called. |
| **RPC_E_NO_GOOD_SECURITY_PACKAGES** | The *asAuthSvc* parameter was not **NULL**, and none of the authentication services in the list could be registered. Check the results saved in *asAuthSvc* for authentication service–specific error codes. |
| **E_OUT_OF_MEMORY** | Out of memory. |

## Remarks

The **CoInitializeSecurity** function initializes the security layer and sets the specified values as the security default. If a process does not call **CoInitializeSecurity**, COM calls it automatically the first time an interface is marshaled or unmarshaled, registering the system default security. No default security packages are registered until then.

This function is called exactly once per process, either explicitly or implicitly. It can be called by the client, server, or both. For legacy applications and other applications that do not explicitly call **CoInitializeSecurity**, COM calls this function implicitly with values from the registry. If you set processwide security using the registry and then call **CoInitializeSecurity**, the [AppID](https://learn.microsoft.com/windows/desktop/com/appid-key) registry values will be ignored and the **CoInitializeSecurity** values will be used.

**CoInitializeSecurity** can be used to override both computer-wide access permissions and application-specific access permissions, but not to override the computer-wide restriction policy.

If *pSecDesc* points to an AppID, the EOAC_APPID flag must be set in *dwCapabilities* and, when the EOAC_APPID flag is set, all other parameters to **CoInitializeSecurity** are ignored. **CoInitializeSecurity** looks for the authentication level under the **AppID** key in the registry and uses it to determine the default security. For more information about how the **AppID** key is used to set security, see [Setting Process-Wide Security Through the Registry](https://learn.microsoft.com/windows/desktop/com/setting-processwide-security-through-the-registry).

If *pSecDesc* is a pointer to an [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol) object, the EOAC_ACCESS_CONTROL flag must be set and *dwAuthnLevel* cannot be none. The **IAccessControl** object is used to determine who can call the process. DCOM will [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) the **IAccessControl** and will [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) it when [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) is called. The state of the **IAccessControl** object should not be changed.

If *pSecDesc* is a pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor), neither the EOAC_APPID nor the EOAC_ACCESS_CONTROL flag can be set in *dwCapabilities*. The owner and group of the **SECURITY_DESCRIPTOR** must be set, and until DCOM supports auditing, the system ACL must be **NULL**. The access-control entries (ACEs) in the discretionary ACL (DACL) of the **SECURITY_DESCRIPTOR** are used to find out which callers are permitted to connect to the process's objects. A DACL with no ACEs allows no access, while a **NULL** DACL will allow calls from anyone. For more information on ACLs and ACEs, see [Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model). Applications should call [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck) (not [IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)) to ensure that their **SECURITY_DESCRIPTOR** is correctly formed prior to calling **CoInitializeSecurity**.

Passing *pSecDesc* as **NULL** is strongly discouraged. An appropriate alternative might be to use a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) that allows Everyone. If *pSecDesc* is **NULL**, the flags in *dwCapabilities* determine how **CoInitializeSecurity** defines the access permissions that a server will use, as follows:

* If the EOAC_APPID flag is set, **CoInitializeSecurity** will look up the application's .exe name in the registry and use the AppID stored there.
* If the EOAC_ACCESS_CONTROL flag is set, **CoInitializeSecurity** will return an error.
* If neither the EOAC_APPID flag nor the EOAC_ACCESS_CONTROL flag is set, **CoInitializeSecurity** allows all callers including Local and Remote Anonymous Users.

The **CoInitializeSecurity** function returns an error if both the EOAC_APPID and EOAC_ACCESS_CONTROL flags are set in *dwCapabilities*.

## See also

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)