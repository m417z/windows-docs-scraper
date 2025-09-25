# PGET_FIRST_ORDERED_SERVICE callback function

## Description

The
**GetFirstOrderedService** function returns the first service in the specified order from the designated subset of services in the table.

## Parameters

### `OrderingMethod` [in]

Specifies the order in which the services are searched. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **STM_ORDER_BY_TYPE_AND_NAME** | Search the services first by type and then by name. |
| **STM_ORDER_BY_INTERFACE_TYPE_NAME** | Search the services first by interface index, then by type, and finally by name. |

### `ExclusionFlags` [in]

Specifies the limits the set of examined services to a subset defined by *ExclusionFlags* and the values in the members of the structure pointed to by the *Service* parameter. See
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle) for a description of the possible flags.

### `Service` [in, out]

Pointer to an
[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service) structure.

On input, the values in the members correspond to flags specified in *ExclusionFlags*.

On output, the first service that matches specified criteria.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | Services that match the specified criteria do not exist. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |

## See also

[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)