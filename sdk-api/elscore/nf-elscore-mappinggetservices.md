# MappingGetServices function

## Description

Retrieves a list of available ELS platform-supported services, along with associated information, according to application-specified criteria.

## Parameters

### `pOptions` [in, optional]

Pointer to a [MAPPING_ENUM_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_enum_options) structure containing criteria to use during enumeration of services. The application specifies **NULL** for this parameter to retrieve all installed services.

### `prgServices` [out]

Address of a pointer to an array of [MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info) structures containing service information matching the criteria supplied in the *pOptions* parameter.

### `pdwServicesCount` [out]

Pointer to a DWORD variable in which this function retrieves the number of retrieved services.

## Return value

Returns S_OK if successful. The function returns an error HRESULT value if it does not succeed.

**Note** The application must test for any failure before proceeding with further operations.

## Remarks

The ELS application can either retrieve all services or filter the services according to specified options. For an associated procedure and code sample, see [Enumerating and Freeing Services](https://learn.microsoft.com/windows/desktop/Intl/enumerating-and-freeing-services).

To avoid resource leaks, the application must free the pointer indicated by *prgServices* with a call to [MappingFreeServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreeservices).

For performance reasons, it is recommended to retrieve services infrequently. For example, if the application needs a specific service, by GUID, it can be enumerated when needed and cached for future use.

## See also

[Enumerating and Freeing Services](https://learn.microsoft.com/windows/desktop/Intl/enumerating-and-freeing-services)

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_ENUM_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_enum_options)

[MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info)

[MappingFreeServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreeservices)