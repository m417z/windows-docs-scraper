# RpcBindingCopy function

## Description

The
**RpcBindingCopy** function copies binding information and creates a new binding handle.

## Parameters

### `SourceBinding`

Server binding handle whose referenced binding information is copied.

### `DestinationBinding`

Returns a pointer to the server binding handle that refers to the copied binding information.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcBindingCopy** function copies the server-binding information referenced by the *SourceBinding* parameter.
**RpcBindingCopy** uses the *DestinationBinding* parameter to return a new server binding handle for the copied binding information.
**RpcBindingCopy** also copies the authentication information from the *SourceBinding* parameter to the *DestinationBinding* parameter.

An application uses
**RpcBindingCopy** when it wants to prevent a change being made to binding information by one thread from affecting the binding information used by other threads.

Once an application calls
**RpcBindingCopy**, operations performed on the *SourceBinding* binding handle do not affect the binding information referenced by the *DestinationBinding* binding handle. Similarly, operations performed on the *DestinationBinding* binding handle do not affect the binding information referenced by the *SourceBinding* binding handle.

If an application wants one thread's changes to binding information to affect the binding information used by other threads, the application should share a single binding handle across the threads. In this case, the application is responsible for binding-handle concurrency control.

When an application is finished using the binding handle specified by the *DestinationBinding* parameter, the application should call the
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) function to release the memory used by the *DestinationBinding* binding handle and its referenced binding information.

**Note** Microsoft RPC supports
**RpcBindingCopy** only in client applications, not in server applications.

## See also

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)