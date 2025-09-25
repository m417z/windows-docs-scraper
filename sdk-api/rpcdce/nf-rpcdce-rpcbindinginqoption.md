# RpcBindingInqOption function

## Description

RPC client processes use
**RpcBindingInqOption** to determine current values of the binding options for a given binding handle.

## Parameters

### `hBinding`

Server binding about which to determine binding-option values.

### `option`

Binding handle property to inquire about.

### `pOptionValue`

Memory location to place the value for the specified *Option*

**Note** For a list of binding options and their possible values, see
[Binding Option Constants](https://learn.microsoft.com/windows/desktop/Rpc/binding-option-constants).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_CANNOT_SUPPORT** | The function is not supported for either the operating system or the transport. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Client processes call
**RpcBindingInqOption** to determine the current settings of the binding handle options. To inquire about authentication settings clients call the
[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient) function. .

## See also

[RPC Message
Queuing](https://learn.microsoft.com/windows/desktop/Rpc/rpc-message-queuing)

[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient)

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)

[RpcBindingSetOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetoption)

[message](https://learn.microsoft.com/windows/desktop/Midl/message)