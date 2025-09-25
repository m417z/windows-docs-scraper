# RpcNsEntryObjectInqDone function

## Description

The
**RpcNsEntryObjectInqDone** function deletes the inquiry context for a name-service database entry's objects.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Pointer to a name-service handle specifying the object UUIDs exported to the *EntryName* parameter specified in the
[RpcNsEntryObjectInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqbegina) function.

An argument value of **NULL** is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsEntryObjectInqDone** function frees an inquiry context created by calling the
[RpcNsEntryObjectInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqbegina) function.

An application calls
**RpcNsEntryObjectInqDone** after viewing exported object UUIDs using the
[RpcNsEntryObjectInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqnext) function.

## See also

[RpcNsEntryObjectInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqbegina)

[RpcNsEntryObjectInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqnext)