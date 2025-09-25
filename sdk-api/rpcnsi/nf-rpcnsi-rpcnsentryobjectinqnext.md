# RpcNsEntryObjectInqNext function

## Description

The
**RpcNsEntryObjectInqNext** function returns one object at a time from a name-service database entry.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Name-service handle that indicates the object UUIDs for a name-service database entry.

### `ObjUuid`

Returns a pointer to an exported object UUID.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_MORE_MEMBERS** | No more members. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsEntryObjectInqNext** function returns one of the object UUIDs exported to the name-service database entry specified by the *EntryName* parameter in the
[RpcNsEntryObjectInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqbegina) function.

An application can view all of the exported object UUIDs by repeatedly calling
**RpcNsEntryObjectInqNext**. When all the object UUIDs have been viewed, this function returns an RPC_S_NO_MORE_MEMBERS status code. The returned object UUIDs are unordered.

The application supplies the memory for the object UUID returned in the *ObjUuid* parameter.

After viewing the object UUIDs, the application must call the
[RpcNsEntryObjectInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqdone) function to release the inquiry context.

The order in which object UUIDs are returned can be different for each viewing of an entry. This means that the order in which object UUIDs are returned to an application can be different each time the application is run.

## See also

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsEntryObjectInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqbegina)

[RpcNsEntryObjectInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsentryobjectinqdone)