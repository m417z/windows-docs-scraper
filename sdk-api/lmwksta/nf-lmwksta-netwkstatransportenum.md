# NetWkstaTransportEnum function

## Description

The **NetWkstaTransportEnum** function supplies information about transport protocols that are managed by the redirector, which is the software on the client computer that generates file requests to the server computer.

## Parameters

### `servername` [in]

A pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

The level of information requested for the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **0** | Return workstation transport protocol information. The *bufptr* parameter points to an array of [WKSTA_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_transport_info_0) structures. |

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA** or **NERR_BufTooSmall**.

### `prefmaxlen` [in]

The preferred maximum length of returned data, in bytes. If you specify **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA** or **NERR_BufTooSmall**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

A pointer to a value that contains a resume handle which is used to continue an existing workstation transport search. The handle should be zero on the first call and left unchanged for subsequent calls. If the *resumehandle* parameter is a **NULL** pointer, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_INVALID_LEVEL** | The level parameter, which indicates what level of data structure information is available, is invalid. This error is returned if the *level* parameter is specified as a value other than zero. |
| **ERROR_INVALID_PARAMETER** | One or more parameters was invalid. This error is returned if the *bufptr* or the *entriesread* parameters are **NULL** pointers. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to process the request. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if a remote server was specified in *servername* parameter, and this request is not supported on the remote server. |
| **NERR_BufTooSmall** | More entries are available. Specify a large enough buffer to receive all entries. This error code is defined in the *Lmerr.h* header file. |

## Remarks

No special group membership is required to successfully execute the
**NetWkstaTransportEnum** function.

## See also

[NetWkstaTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportadd)

[NetWkstaTransportDel](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportdel)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)

[WKSTA_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_transport_info_0)