# RpcBindingFree function

## Description

The
**RpcBindingFree** function releases binding-handle resources.

## Parameters

### `Binding`

Pointer to the server binding to be freed.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcBindingFree** function releases memory used by a server binding handle. Referenced binding information that was dynamically created during program execution is released as well. An application calls the
**RpcBindingFree** function when it is finished using the binding handle. RPC binding handles must not be freed until all calls using the handle have completed; failure to do so will cause unpredictable results.

Binding handles are dynamically created by calling the following functions:

* [RpcBindingCopy](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcopy)
* [RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)
* [RpcBindingServerFromClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingserverfromclient)
* [RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)
* [RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)
* [RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect)

If the operation successfully frees the binding, the *Binding* parameter returns a value of **NULL**.

**Note** Microsoft RPC supports
**RpcBindingFree** only in client applications, or in server applications for binding handles generated with RpcBindingServerFromClient.

## See also

[RpcBindingCopy](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcopy)

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)

[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)