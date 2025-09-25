# PCREATE_STATIC_SERVICE callback function

## Description

The
**CreateStaticService** function adds a static service to the table.

## Parameters

### `InterfaceIndex` [in]

Specifies a unique number that identifies the interface associated with the new service.

### `ServerEntry`

#### - ServiceEntry [in]

Pointer to an
[IPX_STATIC_SERVICE_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374456(v=vs.85)) structure that specifies parameters of the static service to be added.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The SAP Agent is down. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |

## See also

[DeleteStaticService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pdelete_static_service)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_STATIC_SERVICE_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374456(v=vs.85))

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)