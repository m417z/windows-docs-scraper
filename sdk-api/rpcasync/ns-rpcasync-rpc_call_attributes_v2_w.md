# RPC_CALL_ATTRIBUTES_V2_W structure

## Description

The **RPC_CALL_ATTRIBUTES_V2** structure provides parameters to the
[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function. Version 2 specifies support for local addresses and client process IDs.

## Members

### `Version`

Version of the **RPC_CALL_ATTRIBUTES** structure. For this structure, this value must be set to 2.

### `Flags`

Bitmasked flags that indicate which members of this structure should be populated by the call to [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) to which this structure was passed.

| Value | Meaning |
| --- | --- |
| **RPC_QUERY_SERVER_PRINCIPAL_NAME** | Indicates that [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) should populate the **ServerPrincipalName** member of this structure. |
| **RPC_QUERY_CLIENT_PRINCIPAL_NAME** | Indicates that [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) should populate the **ClientPrincipalName** member of this structure. |
| **RPC_QUERY_CALL_LOCAL_ADDRESS** | Indicates that [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) should populate the **CallLocalAddress** member of this structure. |
| **RPC_QUERY_CLIENT_PID** | Indicates that [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) should populate the **ClientPID** member of this structure. This flag is only supported for the ncalrpc protocol sequence. |

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

### `KernelModeCaller`

### `ProtocolSequence`

Constant that indicates the protocol sequence over which the call was made.

### `IsClientLocal`

[RpcCallClientLocality](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpccallclientlocality) enumeration value that indicates the locality of the client (local, remote, or unknown).

### `ClientPID`

Handle that contains the process ID of the calling client. This field is only supported for the ncalrpc protocol sequence, and is populated only when **RPC_QUERY_CLIENT_PID** is specified in the *Flags* parameter.

### `CallStatus`

Bit field that specifies the status of the RPC call.

| Value | Meaning |
| --- | --- |
| **RPC_CALL_STATUS_IN_PROGRESS**<br><br>0x01 | The call is in progress. |
| **RPC_CALL_STATUS_CANCELLED**<br><br>0x02 | The call was canceled. |
| **RPC_CALL_STATUS_DISCONNECTED**<br><br>0x03 | The client has disconnected. |

### `CallType`

[RpcCallType](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpccalltype) enumeration value that indicates the type of the RPC call.

### `CallLocalAddress`

Pointer to a [RPC_CALL_LOCAL_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_local_address_v1) structure that contains information to the server about the local address on which the call was made.

This field must not be **NULL** if **RPC_QUERY_CALL_LOCAL_ADDRESS** is specified in *Flags*; otherwise, RPC_S_INVALID_ARG is returned.

If the buffer supplied by the application is insufficient, [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) returns ERROR_MORE_DATA.

### `OpNum`

The opnum value associated with the call in the corresponding IDL file.

### `InterfaceUuid`

The interface UUID on which the call is made.

#### - KernelMode

Specifies whether or not the call came from kernel mode. Zero indicates the call is not coming from kernel mode; any other value indicates that it was made from kernel mode.

## Remarks

The
**RPC_CALL_ATTRIBUTES** structure uses a versioning scheme to enable the
[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function to incorporate new capabilities without having to introduce new functions with suffix identifiers. For example, a second version of the
**RPC_CALL_ATTRIBUTES**, identified with a simple #define in the header, can add new members to facilitate new functionality built into future versions of the
**RpcServerInqCallAttributes** function, without having to release a corresponding alternative function.

The **Version** member indicates the version of the
**RPC_CALL_ATTRIBUTES** structure (currently either **RPC_CALL_ATTRIBUTES_V1** or **RPC_CALL_ATTRIBUTES_V2**) being used by the calling application. This identification enables the RPC run time to provide backward compatibility for applications not using the most current version of the structure.

 Until the process terminates, **ClientPID** uniquely identifies that process on the client. When the process terminates, the process ID specified by **ClientPID** can be used by new processes.

## See also

[RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa)