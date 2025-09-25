# RPC_BINDING_HANDLE_OPTIONS_V1 structure

## Description

The **RPC_BINDING_HANDLE_OPTIONS_V1** structure contains additional options with which to create an RPC binding handle.

## Members

### `Version`

The version of this structure. For **RPC_BINDING_HANDLE_OPTIONS_V1** this must be set to 1.

### `Flags`

A set of flags describing specific RPC behaviors. This parameter can be set to one or more of the following values. Note that by default, RPC calls use causal order and socket lingering.

| Value | Meaning |
| --- | --- |
| **RPC_BHO_NONCAUSAL** | Specifies causal ordering whereby calls are executed independently of one another rather than in order of submission. |
| **RPC_BHO_DONTLINGER** | Specifies that a socket association must be shutdown after the last binding handle on it is freed. |

### `ComTimeout`

The communication timeout value, specified in microseconds. The default value for RPC is RPC_C_BINDING_DEFAULT_TIMEOUT. This option can be changed later by calling [RpcMgmtSetComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetcomtimeout).

### `CallTimeout`

The call timeout value, specified in microseconds. The default value for RPC is 0.

## Remarks

If this structure is not specified in a call to [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea), the default values for each option are used.

## See also

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle)

[RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind)

[RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea)