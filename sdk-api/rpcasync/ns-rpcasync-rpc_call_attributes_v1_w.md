# RPC_CALL_ATTRIBUTES_V1_W structure

## Description

The
**RPC_CALL_ATTRIBUTES_V1** structure provides parameters to the
[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function. Implemented in ANSI and UNICODE versions for Windows XP and Windows Server 2003 operating systems.

## Members

### `Version`

Version of the
[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function being used by the calling application. See Remarks.

### `Flags`

Bitmask specifying valid flags to request RPC_QUERY_SERVER_PRINCIPAL_NAME or RPC_QUERY_CLIENT_PRINCIPAL_NAME. See Remarks.

### `ServerPrincipalNameBufferLength`

Length of **ServerPrincipalName**, in bytes. If insufficient, **ServerPrincipalName** is unchanged, and **ServerPrincipalNameBufferLength** indicates the required buffer length including the terminating **NULL** character, and ERROR_MORE_DATA is returned. If **ServerPrincipalNameBufferLength** is longer than necessary, upon return it is set to the actual length used, in bytes, including the terminating **NULL** character. See Remarks.

If the protocol sequence does not support retrieving a server principal name, **ServerPrincipalNameBufferLength** is set to zero on return, and the buffer pointed by **ServerPrincipalName** is unmodified. **Windows XP:** Only the **ncacn_*** group of protocol sequences support retrieving the server principal name.

If the RPC_QUERY_SERVER_PRINCIPAL_NAME flag is not specified, **ServerPrincipalNameBufferLength** is ignored. If **ServerPrincipalNameBufferLength** is nonzero and **ServerPrincipalName** is **NULL**, ERROR_INVALID_PARAMETER is returned.

### `ServerPrincipalName`

Pointer to the server principal name, if requested in **Flags** and supported by the protocol sequence. Upon any return value other than RPC_S_OK or ERROR_MORE_DATA, the content of **ServerPrincipalName** is undefined and may have been modified by RPC.

### `ClientPrincipalNameBufferLength`

Length of the buffer pointed to by **ClientPrincipalName**, in bytes. If insufficient, **ClientPrincipalName** is unchanged, and **ClientPrincipalNameBufferLength** indicates the required buffer length including the terminating **NULL** character, and ERROR_MORE_DATA is returned. If **ClientPrincipalNameBufferLength** is longer than necessary, upon return it is set to the actual length used, in bytes, including the terminating **NULL** character.

If the protocol sequence does not support retrieving a client principal name, **ClientPrincipalNameBufferLength** is set to zero on return, and the buffer pointed by **ClientPrincipalName** is unmodified. **Windows XP:** Only the **ncalrpc** protocol sequence supports retrieving the client principal name.

If the RPC_QUERY_CLIENT_PRINCIPAL_NAME flag is not specified, **ClientPrincipalNameBufferLength** is ignored. If **ClientPrincipalNameBufferLength** is nonzero and **ClientPrincipalName** is **NULL**, ERROR_INVALID_PARAMETER is returned.

### `ClientPrincipalName`

Pointer to the client principal name, if requested in **Flags** member and supported by the protocol sequence. Upon any return value other than RPC_S_OK or ERROR_MORE_DATA, the content of **ClientPrincipalName** is undefined and may have been modified by RPC.

### `AuthenticationLevel`

Authentication level for the call. See
[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants) for authentication levels supported by RPC.

### `AuthenticationService`

Authentication service, or security provider, used to make the remote procedure call.

### `NullSession`

Specifies whether a **Null** session is used. Zero indicates the call is not coming over a **Null** session; any other value indicates a **Null** session.

## Remarks

The
**RPC_CALL_ATTRIBUTES** structure uses a versioning scheme to enable the
**RpcServerInqCallAttributes** function to incorporate new capabilities without having to introduce new functions with suffix identifiers. For example, a second version of the
**RPC_CALL_ATTRIBUTES**, identified with a simple #define in the header, can add new members to facilitate new functionality built into future versions of the
**RpcServerInqCallAttributes** function, without having to release a corresponding alternative function.

The **Version** member indicates the version of the
**RPC_CALL_ATTRIBUTES** structure (currently either **RPC_CALL_ATTRIBUTES_V1** or **RPC_CALL_ATTRIBUTES_V2**) being used by the calling application. This identification enables the RPC run time to provide backward compatibility for applications not using the most current version of the structure.

Specifying RPC_QUERY_SERVER_PRINCIPAL_NAME in the **Flags** member directs
**RpcServerInqCallAttributes** to return the server principal name in **ServerPrincipalName**. If RPC_QUERY_SERVER_PRINCIPAL_NAME is not specified,
**RpcServerInqCallAttributes** does not modify the pointer passed in **ServerPrincipalName** and does not store anything in that memory location. Specifying RPC_QUERY_CLIENT_PRINCIPAL_NAME in the **Flags** member directs
**RpcServerInqCallAttributes** to return the client principal name in **ClientPrincipalName**. If RPC_QUERY_CLIENT_PRINCIPAL_NAME is not specified,
**RpcServerInqCallAttributes** does not modify the pointer passed in **ClientPrincipalName** and does not store anything in that memory location.

The best processing mechanism when both client and server principal names are being retrieved is to store the length of **ClientPrincipalNameBufferLength** and **ServerPrincipalNameBufferLength**, and if ERROR_MORE_DATA is returned, compare the stored lengths with the lengths returned in those members. The member with a stored value smaller than or equal to the returned value has returned successfully, indicating that the other member had an insufficient buffer. In the subsequent call, omit the flag for the successfully returned principal name; this avoids processing associated with another retrieval and copy of the successfully returned principal name.

The
**RPC_CALL_ATTRIBUTES_V1** structure is usually called in two ways:

* First approach: zero is specified for the **ServerPrincipalNameBufferLength** or **ClientPrincipalNameBufferLength** member on the first
  **RpcServerInqCallAttributes** function call to retrieve the required buffer length, or to determine whether the protocol supports returning the principal name. Upon retrieving the required buffer length, a buffer is allocated of the required length and a second call is made to get the real length of the buffer.
* Second approach: the caller begins with a reasonable buffer, often allocated on the stack, and if ERROR_MORE_DATA is returned, a buffer of the required length is allocated and the
  [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function is called again.

The second method offers the best performance in most cases, since the caller does not need to perform a memory allocation.

#### Examples

```cpp
RPC_CALL_ATTRIBUTES CallAttributes;  // this maps to RPC_CALL_ATTRIBUTES_V1

memset(&CallAttributes, 0, sizeof(CallAttributes));
CallAttributes.Version = RPC_CALL_ATTRIBUTES_VERSION;    // maps to 1
CallAttributes.Flags = ;//....
Status = RpcServerInqCallAttributes(0, &CallAttributes);

```

## See also

[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants)

[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa)