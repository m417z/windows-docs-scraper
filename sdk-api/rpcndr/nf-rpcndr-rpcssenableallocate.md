# RpcSsEnableAllocate function

## Description

The
**RpcSsEnableAllocate** function establishes the stub memory–management environment.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In cases where the stub memory management is not enabled by the stub itself, an application calls
**RpcSsEnableAllocate** to establish the stub memory–management environment. This environment must be established prior to making a call to
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate). For server manager code called from the stub, the memory-management environment is usually established by the stub itself. Otherwise, call
**RpcSsEnableAllocate** before calling
**RpcSsAllocate**. For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management),
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle), and
[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle).

**Note** The
**RpcSsEnableAllocate** function raises exceptions, while the
[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate) function returns the error code.

## See also

[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssdisableallocate)