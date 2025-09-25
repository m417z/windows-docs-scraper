# RpcRaiseException function

## Description

Use the
**RpcRaiseException** function to raise an exception. The function does not return to the caller.

## Parameters

### `exception`

Exception code for the exception.

## Return value

This function does not return a value.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcRaiseException** raises an exception. The exception handler can then handle the exception. For more information about handling exceptions, see
[Making RPC Function Calls](https://learn.microsoft.com/windows/desktop/Rpc/making-rpc-function-calls).

## See also

[RpcAbnormalTermination](https://learn.microsoft.com/previous-versions/)

[RpcExcept](https://learn.microsoft.com/windows/desktop/api/rpc/nf-rpc-rpcexcept)

[RpcFinally](https://learn.microsoft.com/previous-versions/aa375699(v=vs.80))