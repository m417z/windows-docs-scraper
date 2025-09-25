# RpcSmEnableAllocate function

## Description

The
**RpcSmEnableAllocate** function establishes the stub memory–management environment.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In cases where the stub memory management is not enabled by the server stub itself, applications call
**RpcSmEnableAllocate** to establish the stub memory–management environment. This environment must be established prior to making a call to
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate). In OSF-compatibility (**/osf**) mode, for server manager code called from the stub, the memory-management environment may be established by the server stub itself by using pointer manipulation or the
[enable_allocate](https://learn.microsoft.com/windows/desktop/Midl/enable-allocate) attribute. In default (Microsoft-extended) mode, the environment is established only upon request by using the
[enable_allocate](https://learn.microsoft.com/windows/desktop/Midl/enable-allocate) attribute. Otherwise, call
**RpcSmEnableAllocate** before calling
**RpcSmAllocate**. For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management),
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle), and
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle).

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdisableallocate)