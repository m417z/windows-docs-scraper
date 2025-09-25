# RpcErrorClearInformation function

## Description

The
**RpcErrorClearInformation** function clears all extended error information on the current thread.

## Return value

This function has no return values.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The RPC Runtime usually handles the clearing of extended error information. In only two cases should callers use
**RpcErrorClearInformation**:

* If the calling component adds records to the thread using the
  [RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord) function, then decides it has not encountered a fatal error and continues processing the original, or the error is not connected to the records is has added. In this case, the calling component needs to clear the error information from the thread to prevent the propagation of potentially misleading error information.
* If the calling component attempts multiple retries of an operation that returns extended error information. When an RPC call starts, the RPC Runtime clears any extended error information on the thread. However, if the calling component calls
  [RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord) in a loop with many iterations, it may want to clear the error information, as the extended error information accumulates over time and can exhaust available memory.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)