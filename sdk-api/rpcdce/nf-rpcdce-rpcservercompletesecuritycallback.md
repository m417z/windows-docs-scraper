# RpcServerCompleteSecurityCallback function

## Description

The **RpcServerCompleteSecurityCallback** function completes an asynchronous security callback. This function can cause the call either to be dispatched or fail.

## Parameters

### `BindingHandle` [in]

The Server Call that this function dispatches or fails.

### `Status` [in]

Specifies an RPC status. If this value is not **RPC_S_OK**, the Server Call is failed with a value of **RPC_S_ACCESS_DENIED**.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Return value

This function returns RPC_STATUS.