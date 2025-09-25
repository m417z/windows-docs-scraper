# RpcMgmtInqIfIds function

## Description

The
**RpcMgmtInqIfIds** function returns a vector containing the identifiers of the interfaces offered by the server.

## Parameters

### `Binding`

To receive interface identifiers about a remote application, specify a server binding handle for that application. To receive interface information about your own application, specify a value of **NULL**.

### `IfIdVector`

Returns the address of an interface identifier vector.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtInqIfIds** function to obtain a vector of interface identifiers about the specified server from the RPC run-time library.

The RPC run-time library allocates memory for the interface identifier vector. The application is responsible for calling the
[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree) function to release the memory used by this vector.

The server must be listening for remote procedure calls for this function to succeed. If the server is not listening, the function fails.

## See also

[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree)