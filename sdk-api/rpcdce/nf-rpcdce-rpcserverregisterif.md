# RpcServerRegisterIf function

## Description

The
**RpcServerRegisterIf** function registers an interface with the RPC run-time library.

## Parameters

### `IfSpec`

MIDL-generated structure indicating the interface to register.

### `MgrTypeUuid`

Pointer to a type UUID to associate with the *MgrEpv* parameter. Specifying a null parameter value (or a nil UUID) registers *IfSpec* with a nil-type UUID.

### `MgrEpv`

Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a null value. For more information, please see [RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv).

## Return value

Returns RPC_S_OK upon success.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server can register an unlimited number of interfaces with the RPC run-time library. Registration makes an interface available to clients using a binding handle to the server. To register an interface, the server application code calls
**RpcServerRegisterIf**. For each implementation of an interface that a server offers, it must register a separate manager EPV.

When calling
**RpcServerRegisterIf**, the server provides the following information:

* Interface specification

  The interface specification is a data structure that the MIDL compiler generates. The server specifies the interface using the *IfSpec* parameter.
* Manager type UUID and manager EPV

  The manager type UUID and the manager EPV determine which manager routine executes when a server receives a remote procedure call request from a client.

  The server specifies the manager type UUID and EPV using the *MgrTypeUuid* and *MgrEpv* parameters. Note that when specifying a non-nil manager-type UUID, the server must also call the
  [RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype) function to register objects of this non-nil type.

If your server application needs to register an auto-listen interface or use a callback function for authentication purposes, use
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex).

## See also

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)

[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype)

[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2)

[RpcServerRegisterIf3](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif3)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)

[RpcServerUnregisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterifex)