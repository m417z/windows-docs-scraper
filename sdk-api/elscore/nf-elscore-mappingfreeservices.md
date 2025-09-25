# MappingFreeServices function

## Description

Frees memory and resources allocated for the application to interact with one or more ELS services. The memory and resources are allocated in an application call to [MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices).

## Parameters

### `pServiceInfo` [in]

Pointer to an array of [MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info) structures containing service descriptions retrieved by a prior call to [MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices). This parameter cannot be set to **NULL**.

## Return value

Returns S_OK if successful. The function returns an error HRESULT value if it does not succeed.

## Remarks

**Caution** Services should not be freed before freeing the property bags produced by those services.

Since all services currently run in the application process, the ELS platform does not unload the service DLLs when the services are released. The operating system unloads the DLLs automatically when the application terminates.

## See also

[Enumerating and Freeing Services](https://learn.microsoft.com/windows/desktop/Intl/enumerating-and-freeing-services)

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info)

[MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices)