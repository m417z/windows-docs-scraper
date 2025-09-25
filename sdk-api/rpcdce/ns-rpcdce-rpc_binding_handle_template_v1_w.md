# RPC_BINDING_HANDLE_TEMPLATE_V1_W structure

## Description

The **RPC_BINDING_HANDLE_TEMPLATE_V1** structure contains the basic options with which to create an RPC binding handle.

## Members

### `Version`

The version of this structure. For **RPC_BINDING_HANDLE_TEMPLATE_V1** this must be set to 1.

### `Flags`

Flag values that describe specific properties of the RPC template.

| Value | Meaning |
| --- | --- |
| **RPC_BHT_OBJECT_UUID_VALID** | The **ObjectUuid** member contains a valid value. If this flag is not set, then the ObjectUuid member does not contain a valid UUID. |

### `ProtocolSequence`

A [protocol sequence string literal](https://learn.microsoft.com/windows/desktop/Rpc/protocol-sequence-constants) associated with this binding handle. It can be one of the following values.

**ncalrpc** - Specifies local RPC.
**ncacn_ip_tcp** - Specifies RPC over TCP/IP.
**ncacn_np** - Specifies RPC over named pipes.
**ncacn_http** - Specifies RPC over HTTP.

### `NetworkAddress`

Pointer to a string representation of the network address to bind to.

### `StringEndpoint`

Pointer to a string representation of the endpoint to bind to. If a dynamic endpoint is used, set this member to **NULL**. After the endpoint is resolved, use [RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding) to obtain it.

### `u1`

### `u1.Reserved`

Reserved. This member must be set to **NULL**.

### `ObjectUuid`

The UUID of the remote object. The semantics for this UUID are the same as those for a string binding. After the binding handle is created, call [RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject) to change the UUID as needed.

###### - ProtocolSequence.ncacn_http (Specifies RPC over HTTP.)

###### - ProtocolSequence.ncacn_ip_tcp (Specifies RPC over TCP/IP.)

###### - ProtocolSequence.ncacn_np (Specifies RPC over named pipes.)

###### - ProtocolSequence.ncalrpc (Specifies local RPC.)

## Remarks

Fast binding handles are slightly different from "classic" binding handles in the way they are handled during calls to [RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset). **RpcBindingReset** is a no-op call for static fast binding handles. For classic binding handles, however, **RpcBindingReset** converts a static binding handle into a dynamic one to preserve backwards compatibility.

The following table demonstrates the behavior of static and dynamic binding handles with regards to [RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset) and [RpcEpResolveBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepresolvebinding).

| Endpoint Type | Static | | Dynamic | |
| --- | --- | --- | --- | --- |
| Binding Handle Type | Fast | Classic | Fast | Classic |
| [RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset) | No-op | Converts to dynamic | Removes resolved endpoint if one is present | Removes resolved endpoint if one is present |
| [RpcEpResolveBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepresolvebinding) | No-op | No-op | Resolves endpoint if not previously resolved | Resolves endpoint if not previously resolved |

## See also

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle)

[RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind)

[RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea)