# PBLOCK_CONVERT_SERVICES_TO_STATIC callback function

## Description

The
**BlockConvertServicesToStatic** function converts all services received on a specified interface to static.

## Parameters

### `InterfaceIndex` [in]

Specifies the unique number that identifies the interface associated with the services intended for conversion.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The SAP Agent is down. |
| **ERROR_INVALID_PARAMETER** | The parameter is invalid. |

## See also

[BlockDeleteStaticServices](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pblock_delete_static_services)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)