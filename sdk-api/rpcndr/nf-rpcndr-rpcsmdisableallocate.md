# RpcSmDisableAllocate function

## Description

The
**RpcSmDisableAllocate** function frees resources and memory within the stub memory–management environment.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcSmDisableAllocate** function frees all the resources used by a call to
[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate). It also releases memory allocated by a call to
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate) after the call to
**RpcSmEnableAllocate** and marked for deletion by the
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree) function.

Note that
[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate) and
**RpcSmDisableAllocate** must be used together as matching pairs.

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate)