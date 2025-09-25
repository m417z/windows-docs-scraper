# I_RpcBindingInqLocalClientPID function

## Description

[The **I_RpcBindingInqLocalClientPID** function is available for use in the operating systems specified in the Requirements section. Instead, call [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa).]

The **I_RpcBindingInqLocalClientPID** function obtains a client process ID.

## Parameters

### `Binding` [in, optional]

**RPC_BINDING_HANDLE** that specifies the binding handle for an explicit RPC binding from the client to a server application.

### `Pid` [out]

Contains the process ID of the client that issued the call upon return.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The function call was successful. |
| **RPC_S_NO_CALL_ACTIVE** | The current thread does not have an active RPC call. |
| **RPC_S_INVALID_BINDING** | The RPC binding handle is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The client process ID is only returned in *ClientBinding* when the "ncalrpc" protocol sequence is used. Until the process terminates, the process ID value uniquely identifies it on the client. When the process terminates, the process ID can be used by new processes.