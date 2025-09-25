# PBLOCK_DELETE_STATIC_SERVICES callback function

## Description

The
**BlockDeleteStaticServices** function deletes all static services associated with a specified interface.

## Parameters

### `InterfaceIndex` [in]

Specifies the unique number that identifies the interface associated with the services to be deleted.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The SAP Agent is down. |
| **ERROR_INVALID_PARAMETER** | The parameter is invalid. |

## See also

[BlockConvertServicesToStatic](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pblock_convert_services_to_static)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)