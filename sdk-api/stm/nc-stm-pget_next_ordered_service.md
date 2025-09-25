# PGET_NEXT_ORDERED_SERVICE callback function

## Description

The
**GetNextOrderedService** function returns the next service from a subset of services in the table. The service returned is the next service after a given input service using the ordering method specified.

## Parameters

### `OrderingMethod` [in]

Specifies the order in which the services are searched. See
[GetFirstOrderedService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pget_first_ordered_service) for a description of the various ordering methods.

### `ExclusionFlags` [in]

Limits the set of examined services to a subset defined by *ExclusionFlags* and the values in the corresponding members of the structure pointed to by the *Service* parameter. See
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle) for a description of the possible flags.

### `Service` [in, out]

Pointer to an
[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service) structure.

On input, specifies the service from which to continue searching; also contains member values that correspond to the specified *ExclusionFlags*.

On output, the structure contains the first service that follows the input service and matches the specified criteria.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_NO_MORE_SERVICES** | There are no more services matching the specified criteria. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |

## See also

[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)