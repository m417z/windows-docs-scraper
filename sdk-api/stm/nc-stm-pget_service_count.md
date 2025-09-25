# PGET_SERVICE_COUNT callback function

## Description

The
**GetServiceCount** function returns the number of services in the table.

## Parameters

### `unnamedParam1`

## Return value

If the function succeeds, the return value is the number of services in the table.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **NO_ERROR** | Operation succeeded but no services are available. |
| **0 (Zero)** | No services are available in the table or the operation failed. Call [GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror) to obtain more information. |

## See also

[GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)