# RpcServerInqIf function

## Description

The
**RpcServerInqIf** function returns the manager entry-point vector (EPV) registered for an interface.

## Parameters

### `IfSpec`

Interface whose manager EPV is returned.

### `MgrTypeUuid`

Pointer to the manager type UUID whose manager EPV is returned.

Specifying a parameter value of **NULL** (or a nil UUID) signifies to return the manager EPV registered with *IfSpec* and the nil manager type UUID.

### `MgrEpv`

Returns a pointer to the manager EPV for the requested interface.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_UNKNOWN_IF** | The interface is unknown. |
| **RPC_S_UNKNOWN_MGR_TYPE** | The manager type is unknown. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls the
**RpcServerInqIf** function to determine the manager EPV for a registered interface and manager type UUID.

## See also

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)