# MprConfigFilterSetInfo function

## Description

The **MprConfigFilterSetInfo** function sets the static filtering information for a specified transport protocol type.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `dwLevel` [in]

A **DWORD** value that describes the format in which the information is structured in the *lpBuffer* parameter. Must be zero.

### `dwTransportId` [in]

A **DWORD** value that describes the transport protocol type of the static filtering information in the *lpBuffer* parameter. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `lpBuffer` [in]

A pointer to a [MPR_FILTER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_filter_0) structure that contains the filter driver configuration information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *hMprConfig* or *lpBuffer* is **NULL**, or *dwLevel* is not set to 0. |

## See also

[MPR_FILTER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_filter_0)

[MprConfigFilterGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigfiltergetinfo)