# RpcSsDontSerializeContext function

## Description

The
**RpcSsDontSerializeContext** function disables run-time serialization of multiple calls dispatched to server-manager routines on the same context handle. Use of this function is not recommended. Developers should use mixed mode–content handle serialization instead. The See Also section provides links to more appropriate functions.

## Remarks

The
**RpcSsDontSerializeContext** function prevents the run time from performing this serialization service, allowing multiple calls to be dispatched on a given context handle. Calling this function does not disable serialization entirely—when a context run down occurs, your context run-down routine will not run until all outstanding client requests have completed. Changes to the context handle state, including freeing the context handle typically, must continue to be serialized.

It is recommended that, if your distributed application invokes the
**RpcSsDontSerializeContext** function, the call should be made before the server program begins handling remote procedure calls.

**Note** Typically, the RPC run-time serializes calls on the same context handle dispatched to server manager routines. Context handles are maintained on a per-client basis and typically represent the server-side state. This means that your server manager does not have to guard against another thread from the same client changing the context or against the context running down while a call is dispatched.

**Note** After it is called, the
**RpcSsDontSerializeContext** function is not revertible for the life of the process.

## See also

[Multithreaded Clients and Context Handles](https://learn.microsoft.com/windows/desktop/Rpc/multithreaded-clients-and-context-handles)

[RpcSsContextLockExclusive](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockexclusive)

[RpcSsContextLockShared](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockshared)

[Server
Context Run-down Routine](https://learn.microsoft.com/windows/desktop/Rpc/server-context-run-down-routine)

[context_handle_noserialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-noserialize)

[context_handle_serialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-serialize)