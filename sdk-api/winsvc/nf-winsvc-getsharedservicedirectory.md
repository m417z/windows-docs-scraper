## Description

Returns a path for a per-service filesystem location for a service and associated programs to read and/or write state to.

## Parameters

### `ServiceHandle`

A handle to the service. This handle is returned by the [OpenService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-openservicea) function.

### `DirectoryType`

A member of the [SERVICE_SHARED_DIRECTORY_TYPE](https://learn.microsoft.com/windows/win32/api/winsvc/ne-winsvc-service_shared_directory_type) enumeration that identifies the type of per-service shared directory path to retrieve.

### `PathBuffer`

A caller-allocated buffer into which the path string will be copied. If NULL, the function call will fail with ERROR_INSUFFICIENT_BUFFER and return the required buffer length, in WCHARs, in *RequiredBufferLength*. If non-NULL, the length of the buffer should be specified in *PathBufferLength*. The path, if written, will be NULL terminated.

### `PathBufferLength`

The length of the buffer supplied in *PathBuffer*, in units of WCHARS. This argument is ignored if *PathBuffer* is NULL.

### `RequiredBufferLength`

This value is set to the required length of the buffer in units of WCHARs. This length includes the terminating NULL character.

## Return value

Returns ERROR_SUCCESS when all operations complete successfully and the NULL-terminated state path is written to *PathBuffer*. Returns ERROR_INSUFFICIENT_BUFFER if *PathBuffer* was not large enough to contain the state path, or if *PathBuffer* was NULL. In this case the required buffer length in WCHARs is returned via *RequiredBufferLength*. If some other failure occurs, a Win32 error code is returned.

## Remarks

For **ServiceSharedDirectoryPersistentState**, the security of the directory is set to only provide write access to the local system account, the service SID, and to local administrators. Ensure service SIDs are enabled for any service that calls this API. For more information, see [SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info).

For a similar API that provides service state exclusively for use by the service itself, see [GetServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getservicedirectory).

All service state directories are deleted by the service control manager once the service is uninstalled.

## See also

[OpenService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-openservicea)

[GetServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getservicedirectory)

[SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info)