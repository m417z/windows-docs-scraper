# NetShareDelEx function

## Description

Deletes a share name from a server's list of shared resources, which disconnects all connections to that share. This function, which is an extended version of the [NetShareDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedel) function, allows the caller to specify a [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0), [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1), [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2), [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502), or [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0, 1, 2, or 502** | Specifies information about the shared resource, including the name of the resource, type and permissions, and number of connections. The *buf* parameter points to a [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0), [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1), [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2), or [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure. |
| **503** | Specifies information about the shared resource, including the name of the resource, type and permissions, number of connections, and other pertinent information. The *buf* parameter points to a [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INTERNAL_ERROR** | An internal error occurred. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |

## Remarks

If 503 is specified for the *level* parameter, the *buf* parameter points to a [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure, and the **shi503_netname** and **shi503_servername** members of that structure are used to look up the shared resource on the server; the other members are ignored. The remote server specified in the **shi503_servername** member must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. In the call to **NetServerTransportAddEx**, either 2 or 3 must have been specified for the *level* parameter, and the **SVTI2_SCOPED_NAME** flag must have been specified in the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure for the transport protocol.

If 0, 1, 2, or 502 is specified for the *level* parameter, the *buf* parameter points to a [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0), [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1), [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2), or [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure, and the **shi0_netname**, **shi1_netname**, **shi2_netname**, or **shi502_netname** member of that structure is used; the other members are ignored.

## See also

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedel)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)

[SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0)

[SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1)

[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2)

[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)