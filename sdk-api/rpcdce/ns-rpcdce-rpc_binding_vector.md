# RPC_BINDING_VECTOR structure

## Description

The
**RPC_BINDING_VECTOR** structure contains a list of binding handles over which a server application can receive remote procedure calls.

## Members

### `Count`

Number of binding handles present in the binding-handle array **BindingH**.

### `BindingH`

Array of binding handles that contains **Count** elements.

## Remarks

The binding vector contains a count member (**Count**), followed by an array of binding-handle (**BindingH**) elements.

The RPC run-time library creates binding handles when a server application registers protocol sequences. To obtain a binding vector, a server application calls
[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings).

A client application obtains a binding vector of compatible servers from the name-service database by calling
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext).

In both routines, the RPC run-time library allocates memory for the binding vector. An application calls
[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree) to free the binding vector.

To remove an individual binding handle from the vector, the application must set the value in the vector to **NULL**. When setting a vector element to **NULL**, the application must:

* Free the individual binding.
* Not change the value of **Count**.

Calling
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) allows an application to free all binding handles in the vector.

## See also

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)

[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)