# RpcServerInqBindings function

## Description

The
**RpcServerInqBindings** function returns the binding handles over which remote procedure calls can be received.

## Parameters

### `BindingVector`

Returns a pointer to a pointer to a vector of server binding handles.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_BINDINGS** | There are no bindings. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcServerInqBindings** to obtain a vector of server binding handles. The RPC run-time library creates binding handles when a server application calls the following functions to register protocol sequences:

* [RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)
* [RpcServerUseAllProtseqsEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsex)
* [RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)
* [RpcServerUseAllProtseqsIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsifex)
* [RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)
* [RpcServerUseProtseqEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqex)
* [RpcServerUseProtseqEpEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqepex)
* [RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)
* [RpcServerUseProtseqIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqifex)
* [RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

The returned binding vector can contain binding handles with dynamic endpoints or binding handles with well-known endpoints, depending on which of the above functions the server application called.

A server uses the vector of binding handles for exporting to the name service, for registering with the local endpoint-map database, or for conversion to string bindings. If there are no binding handles (no registered protocol sequences), this routine returns the RPC_S_NO_BINDINGS status code and a *BindingVector* parameter value of NULL. The server is responsible for calling the
[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree) function to release the memory used by the vector.

## See also

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)