# RpcMgmtEpEltInqBegin function

## Description

The
**RpcMgmtEpEltInqBegin** function creates an inquiry context for viewing the elements in an endpoint map.

## Parameters

### `EpBinding`

Binding handle to a host whose endpoint-map elements is to be viewed. Specify **NULL** to view elements from the local host. If a binding handle is specified, the object UUID on the binding handle must be **NULL**. If present, the endpoint on the binding handle is ignored and the endpoint to the endpoint mapper database on the given host is used.

### `InquiryType`

Integer value that indicates the type of inquiry to perform on the endpoint map. The following are valid inquiry types.

| Value | Meaning |
| --- | --- |
| **RPC_C_EP_ALL_ELTS** | Returns every element from the endpoint map. The *IfId*, *VersOption*, and *ObjectUuid* parameters are ignored. |
| **RPC_C_EP_MATCH_BY_IF** | Searches the endpoint map for elements that contain the interface identifier specified by the *IfId* and *VersOption* values. |
| **RPC_C_EP_MATCH_BY_OBJ** | Searches the endpoint map for elements that contain the object UUID specified by *ObjectUuid*. |
| **RPC_C_EP_MATCH_BY_BOTH** | Searches the endpoint map for elements that contain the interface identifier and object UUID specified by *IfId*, *VersOption*, and *ObjectUuid*. |

### `IfId`

Interface identifier of the endpoint-map elements to be returned by
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext). This parameter is only used when *InquiryType* is either RPC_C_EP_MATCH_BY_IF or RPC_C_EP_MATCH_BY_BOTH. Otherwise, it is ignored.

### `VersOption`

Specifies how
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext) uses the *IfId* parameter. This parameter is only used when *InquiryType* is either RPC_C_EP_MATCH_BY_IF or RPC_C_EP_MATCH_BY_BOTH. Otherwise, it is ignored. The following are valid values for this parameter.

| Value | Meaning |
| --- | --- |
| **RPC_C_VERS_ALL** | Returns endpoint-map elements that offer the specified interface [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid), regardless of the version numbers. |
| **RPC_C_VERS_COMPATIBLE** | Returns endpoint-map elements that offer the same major version of the specified interface [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) and a minor version greater than or equal to the minor version of the specified interface **UUID**. |
| **RPC_C_VERS_EXACT** | Returns endpoint-map elements that offer the specified version of the specified interface [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). |
| **RPC_C_VERS_MAJOR_ONLY** | Returns endpoint-map elements that offer the same major version of the specified interface [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) and ignores the minor version. |
| **RPC_C_VERS_UPTO** | Returns endpoint-map elements that offer a version of the specified interface [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) less than or equal to the specified major and minor version. |

### `ObjectUuid`

The object UUID that
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext) looks for in endpoint-map elements. This parameter is used only when *InquiryType* is either RPC_C_EP_MATCH_BY_OBJ or RPC_C_EP_MATCH_BY_BOTH.

### `InquiryContext`

Returns an inquiry context for use with
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext) and
[RpcMgmtEpEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqdone). See
[RPC_EP_INQ_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-ep-inq-handle).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcMgmtEpEltInqBegin** function creates an inquiry context for viewing server-address information stored in the endpoint map. Using *InquiryType* and *VersOption*, an application specifies which of the following endpoint-map elements are to be returned from calls to
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext):

* All elements
* Those elements with the specified interface identifier
* Those elements with the specified object UUID
* Those elements with both the specified interface identifier and object UUID

Before calling
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext), the application must first call this function to create an inquiry context. After viewing the endpoint-map elements, the application calls
[RpcMgmtEpEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqdone) to delete the inquiry context.

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcMgmtEpEltInqDone](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqdone)

[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext)