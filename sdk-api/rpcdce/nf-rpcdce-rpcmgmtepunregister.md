# RpcMgmtEpUnregister function

## Description

[This function is supported only on Windows NT and Windows Me/98/95; it returns EP_S_CANT_PERFORM_OP on other versions of Windows.]

The
**RpcMgmtEpUnregister** function removes server address information from an endpoint map.

## Parameters

### `EpBinding`

Host whose endpoint-map elements are to be unregistered. To remove elements from the same host as the calling application, the application specifies a value of **NULL**. To remove elements from another host, the application specifies a server binding handle for any server residing on that host. Note that the application can specify the same binding handle it is using to make other remote procedure calls.

### `IfId`

Interface identifier to remove from the endpoint map.

### `Binding`

Binding handle to remove.

### `ObjectUuid`

Optional object UUID to remove. The value **NULL** indicates there is no object UUID to remove.

## Return value

| Return code | Description |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_CANT_PERFORM_OP** | Cannot perform the requested operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcMgmtEpUnregister** function unregisters an element from the endpoint map. A management program calls this function to remove addresses of servers that are no longer available, or to remove addresses of servers that support objects that are no longer offered.

The *EpBinding* parameter must be a full binding. The object UUID associated with the *EpBinding* parameter must be a nil UUID. Specifying a non-nil UUID causes the function to fail with the status code EPT_S_CANT_PERFORM_OP. Other than the host information and object UUID, all information in this argument is ignored.

An application calls
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext) to view local endpoint-map elements. The application can then remove the elements using
**RpcMgmtEpUnregister**.

**Note** Use this function with caution. Removing elements from the local endpoint map may make servers unavailable to client applications that do not already have a fully-bound binding handle to the server.

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister)

[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext)