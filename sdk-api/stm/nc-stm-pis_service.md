# PIS_SERVICE callback function

## Description

The
**IsService** function checks whether a service of specified type and name exists in the service table, and optionally returns the service's parameters.

## Parameters

### `Type` [in]

Specifies the type of the service being checked.

### `Name` [in]

Specifies the name of the service being checked.

### `Service` [out]

Pointer to a structure in which to receive the information about the matching service (if any).

## Return value

The
**IsService** function returns one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | The service exists in the table. |
| **FALSE** | No such service exists, or the operation failed. Call [GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror) for more information about the failure. |
| **NO_ERROR** | The operation succeeded, but no such service exists. |
| **ERROR_INVALID_PARAMETER** | The service type or name is invalid. |

## See also

[GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)