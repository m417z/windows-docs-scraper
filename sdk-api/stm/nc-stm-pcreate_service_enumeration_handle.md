# PCREATE_SERVICE_ENUMERATION_HANDLE callback function

## Description

The
**CreateServiceEnumerationHandle** function returns a handle that allows the use of fast and change-tolerant enumeration functions. Such functions can scan through all services or a specified subset. The functions are change-tolerant in that they automatically enumerate any changes that other processes make to the set of enumerated services

## Parameters

### `ExclusionFlags` [in]

Specifies the limits the set of services that
**CreateServiceEnumerationHandle** returns to a subset defined by a combination of *ExclusionFlags* and values in the corresponding members of *CriteriaService*. This parameter is one of the following values.

| Value | Meaning |
| --- | --- |
| **STM_ONLY_THIS_INTERFACE** | Enumerate only those services that were obtained through the interface specified in the **InterfaceIndex** member of *CriteriaService*. |
| **STM_ONLY_THIS_PROTOCOL** | Enumerate only those services that were obtained through the protocol specified in the **Protocol** member of *CriteriaService*. For example, IPX_PROTOCOL_SAP for services obtained by the DLL protocol or IPX_PROTOCOL_STATIC for services maintained by the router manager. |
| **STM_ONLY_THIS_TYPE** | Enumerate only those services that have the same type as those in the **Service** member of *CriteriaService* |

### `CriteriaService` [in]

Pointer to an
[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service) structure with member values that correspond to those specified in *ExclusionFlags*.

## Return value

If the function succeeds, the return value is a handle for use with the service enumeration function.

A **NULL** handle indicates no services exists with the specified criteria, or that the operation failed. For more information, call
[GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror) and check the error code against the table below.

| Value | Description |
| --- | --- |
| **ERROR_NO_SERVICES** | No services exist with the specified criteria. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |

## See also

[CloseServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pclose_service_enumeration_handle)

[EnumerateGetNextService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-penumerate_get_next_service)

[GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror)

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVICE](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_service)

[Service Table Management Functions](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-functions)