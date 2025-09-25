# PCLOSE_SERVICE_ENUMERATION_HANDLE callback function

## Description

The
**CloseServiceEnumerationHandle** function terminates the enumeration and frees associated resources.

## Parameters

### `EnumerationHandle` [in]

Handle that specifies the enumeration to terminate, obtained from a previous call to
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle).

## Return value

If the functions succeeds, the return value is NO_ERROR.

If the function fails, the return value is ERROR_CAN_NOT_COMPLETE.

## See also

[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)