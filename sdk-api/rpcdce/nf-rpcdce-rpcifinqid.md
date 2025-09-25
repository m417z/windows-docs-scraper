# RpcIfInqId function

## Description

The
**RpcIfInqId** function returns the interface-identification part of an interface specification.

## Parameters

### `RpcIfHandle`

Stub-generated structure specifying the interface to query.

### `RpcIfId`

Returns a pointer to the interface identification. The application provides memory for the returned data.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcIfInqId** function to obtain a copy of the interface identification from the provided interface specification.

The returned interface identification consists of the interface UUID and interface version numbers (major and minor) specified in the *IfSpec* parameter from the IDL file.

## See also

[RpcServerInqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqif)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)