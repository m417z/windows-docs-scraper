# RpcServerRegisterAuthInfoA function

## Description

The
**RpcServerRegisterAuthInfo** function registers authentication information with the RPC run-time library.

## Parameters

### `ServerPrincName`

Pointer to the principal name to use for the server when authenticating remote procedure calls using the service specified by the *AuthnSvc* parameter. The content of the name and its syntax are defined by the authentication service in use. For more information, see
[Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names).

### `AuthnSvc`

Authentication service to use when the server receives a request for a remote procedure call.

### `GetKeyFn`

Address of a server-application-provided routine that returns encryption keys. See
[RPC_AUTH_KEY_RETRIEVAL_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_auth_key_retrieval_fn).

Specify a **NULL** parameter value to use the default method of encryption-key acquisition. In this case, the authentication service specifies the default behavior. Set this parameter to **NULL** when using the RPC_C_AUTHN_WINNT authentication service.

| Authentication service | GetKeyFn | Arg | Run-time behavior |
| --- | --- | --- | --- |
| RPC_C_AUTHN_DPA | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_GSS_KERBEROS | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_GSS_NEGOTIATE | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_GSS_SCHANNEL | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_MQ | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_MSN | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_WINNT | Ignored | Ignored | Does not support |
| RPC_C_AUTHN_DCE_PRIVATE | **NULL** | Non-**null** | Uses default method of encryption-key acquisition from specified key table; specified argument is passed to default acquisition function. |
| RPC_C_AUTHN_DCE_PRIVATE | Non-**null** | **NULL** | Uses specified encryption-key acquisition function to obtain keys from default key table. |
| RPC_C_AUTHN_DCE_PRIVATE | Non-**null** | Non-**null** | Uses specified encryption-key acquisition function to obtain keys from specified key table; specified argument is passed to acquisition function. |
| RPC_C_AUTHN_DEC_PUBLIC | Ignored | Ignored | Reserved for future use. |

The RPC run-time library passes the *ServerPrincName* parameter value from
**RpcServerRegisterAuthInfo** as the *ServerPrincName* parameter value to the *GetKeyFn* acquisition function. The RPC run-time library automatically provides a value for the key version (*KeyVer*) parameter. For a *KeyVer* parameter value of zero, the acquisition function must return the most recent key available. The retrieval function returns the authentication key in the *Key* parameter.

If the acquisition function called from
**RpcServerRegisterAuthInfo** returns a status other than RPC_S_OK, then this function fails and returns an error code to the server application. If the acquisition function called by the RPC run-time library while authenticating a client's remote procedure call request returns a status other than RPC_S_OK, the request fails and the RPC run-time library returns an error code to the client application.

### `Arg`

Pointer to a parameter to pass to the *GetKeyFn* routine, if specified. This parameter can also be used to pass a pointer to an
[SCHANNEL_CRED](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_cred) structure to specify explicit credentials if the authentication service is set to SCHANNEL.

If the *Arg* parameter is set to **NULL**, this function will use the default certificate or credential if it has been set up in the directory service.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_UNKNOWN_AUTHN_SERVICE** | The authentication service is unknown. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcServerRegisterAuthInfo** to register an authentication service to use for authenticating remote procedure calls. A server calls this routine once for each authentication service the server wants to register. If the server calls this function more than once for a given authentication service, the results are undefined.

The authentication service that a client application specifies (using
[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) or
**RpcServerRegisterAuthInfo**) must be one of the authentication services specified by the server application. Otherwise, the client's remote procedure call fails and an RPC_S_UNKNOWN_AUTHN_SERVICE status code is returned.

> [!NOTE]
> The rpcdce.h header defines RpcServerRegisterAuthInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)