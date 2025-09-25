# RpcEpResolveBinding function

## Description

The
**RpcEpResolveBinding** function resolves a partially-bound server binding handle into a fully-bound server binding handle.

## Parameters

### `Binding`

Partially-bound server binding handle to resolve to a fully-bound server binding handle.

### `IfSpec`

Stub-generated structure specifying the interface of interest.

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
**RpcEpResolveBinding** function to resolve a partially-bound server binding handle into a fully-bound binding handle.

Resolving binding handles requires an interface UUID and an object UUID (which may be nil). The RPC run-time library asks the endpoint-mapping service on the host specified by the *Binding* parameter to look up an endpoint for a compatible server instance. To find the endpoint, the endpoint-mapping service looks in the endpoint-map database for the interface UUID in the *IfSpec* parameter and the object UUID in the *Binding* parameter, if any.

How the resolve-binding operation functions depends on whether the specified binding handle is partially- or fully-bound. When the client specifies a partially-bound handle, the resolve-binding operation has the following possible outcomes:

* If no compatible server instances are registered in the endpoint-map database, the resolve-binding operation returns the EPT_S_NOT_REGISTERED status code.
* If a compatible server instance is registered in the endpoint-map database, the resolve-binding operation returns a fully-bound binding and the RPC_S_OK status code.

When the client specifies a fully-bound binding handle, the resolve-binding operation returns the specified binding handle and the RPC_S_OK status code. The resolve-binding operation does not contact the endpoint-mapping service.

In neither the partially- nor the fully-bound binding case does the resolve-binding operation contact a compatible server instance.

**Note** Calling
**RpcEpResolveBinding** is not strictly necessary. If an RPC call is made on a partially-bound server binding handle, the RPC run time takes the necessary steps to make the binding into fully bound binding handle. The RPC run time calls
**RpcEpResolveBinding**, but does so more efficiently due to additional caching techniques. In Windows XP and Windows 2000, applications have no reason to call
**RpcEpResolveBinding**.

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone)

[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)