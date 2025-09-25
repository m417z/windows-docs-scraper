# RpcSsDisableAllocate function

## Description

The
**RpcSsDisableAllocate** function frees resources and memory within the stub memory–management environment.

## Return value

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcSsDisableAllocate** frees all the resources used by a call to
[RpcSsEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssenableallocate). It also releases memory that was allocated by a call to
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate) after the call to
**RpcSsEnableAllocate**.

[RpcSsEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssenableallocate) and
**RpcSsDisableAllocate** must be used together as matching pairs.

## See also

[RpcSmDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdisableallocate)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssenableallocate)