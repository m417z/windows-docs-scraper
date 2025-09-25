# PENUMERATE_GET_NEXT_SERVICE callback function

## Description

The
**EnumerateGetNextService** function returns the next service entry in an enumeration started by
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle).

## Parameters

### `EnumerationHandle` [in]

Handle that identifies the enumeration and specifies the subset of services on which the enumeration will operate. The handle is obtained from a call to
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle).

### `Service` [out]

Pointer to an
[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service) structure that contains the next service in the enumeration. The services are returned in no particular order, and each service in the subset is returned only once.

## Return value

If the function succeeds, the buffer pointed to by the *Service* parameter receives the next service in the enumeration. In this case the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | No more services exist with the specified criteria. |
| **ERROR_CAN_NOT_COMPLETE** | The operation failed. |

## See also

[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)