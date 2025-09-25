# RpcBindingSetOption function

## Description

The
**RpcBindingSetOption** function enables client applications to specify message-queuing options on a binding handle.

## Parameters

### `hBinding`

Server binding to modify.

### `option`

Binding property to modify. For a list of binding options and their possible values, see
[Binding Option Constants](https://learn.microsoft.com/windows/desktop/Rpc/binding-option-constants). See Remarks for information on the RPC Call time-out feature.

### `optionValue`

New value for the binding property. See Remarks.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_CANNOT_SUPPORT** | The function is not supported for either the operating system or the transport. Note that calling **RpcBindingSetOption** on binding handles that use any protocol sequence other than **ncacn_*** will fail and return this value. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

RPC client processes use
**RpcBindingSetOption** to control the delivery quality-of-service, call logging, and call lifetimes. Changing the binding-handle properties will affect all remote calls until the properties are changed by another call to
**RpcBindingSetOption**. You can also call
[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) to set security options for the binding handle.

**Windows XP:** RPC Call Timeout feature:

Calling the
**RpcBindingSetOption** function with *Option* set to RPC_C_OPT_CALL_TIMEOUT and *OptionValue* set to the time-out value (in milliseconds) enables developers to set an RPC-server time-out that prevents a thread from becoming captive to an unresponsive RPC server. This feature saves developers from explicitly canceling a call to an unresponsive RPC server. The timer monitoring for time-out is reset by the RPC client upon receipt of each packet. If the time-out expires without receiving a packet from the server, the RPC client returns RPC_S_CALL_CANCELLED. Note that the RPC server may still eventually execute a call, even though the client will discard the response.

Set *OptionValue* to INFINITE or zero for an infinite time-out. Do not change this option from another thread while a call is in progress. Do not attempt to retry a canceled call; doing so increases the burden on the already unresponsive server. The RPC call time-out feature is only useful for connection-oriented, synchronous RPC calls, such as those made on **ncacn_*** protocol sequences. For datagram, asynchronous, or local RPC calls, this option is ignored by the RPC run-time.

The RPC call time-out feature is useful in many situations, such as user interface updates that would otherwise wait for the busy RPC server to respond (leaving the user watching an hourglass), or when many RPC servers can service a request, thereby enabling clients to more quickly identify and bypass unresponsive servers.

## See also

[RPC Message
Queuing](https://learn.microsoft.com/windows/desktop/Rpc/rpc-message-queuing)

[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient)

[RpcBindingInqOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqoption)

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)

[message](https://learn.microsoft.com/windows/desktop/Midl/message)