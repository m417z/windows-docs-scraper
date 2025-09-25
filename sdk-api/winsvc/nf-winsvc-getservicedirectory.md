## Description

Returns a path for a per-service filesystem location for a service to read and/or write state to.

## Parameters

### `hServiceStatus`

A handle to the status information structure for the current service. This handle is returned by the [RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-registerservicectrlhandlera) function.

### `eDirectoryType`

A member of the [SERVICE_DIRECTORY_TYPE](https://learn.microsoft.com/windows/win32/api/winsvc/ne-winsvc-service_directory_type) enumeration that identifies the type of per-service directory path to retrieve.

### `lpPathBuffer`

A caller-allocated buffer into which the path string will be copied. If NULL, the function call will fail with ERROR_INSUFFICIENT_BUFFER and return the required buffer length, in WCHARs, in *lpcchRequiredBufferLength*. If non-NULL, the length of the buffer should be specified in *cchPathBufferLength*. The path, if written, will be NULL terminated.

### `cchPathBufferLength`

The length of the buffer supplied in *lpPathBuffer*, in units of WCHARS. This argument is ignored if *lpPathBuffer* is NULL.

### `lpcchRequiredBufferLength`

This value is set to the required length of the buffer in units of WCHARs. This length includes the terminating NULL character.

## Return value

Returns ERROR_SUCCESS when all operations complete successfully and the NULL-terminated state path is written to *lpPathBuffer*. Returns ERROR_INSUFFICIENT_BUFFER if *lpPathBuffer* was not large enough to contain the state path, or if *lpPathBuffer* was NULL. In this case the required buffer length in WCHARs is returned via *lpcchRequiredBufferLength*. If some other failure occurs, a Win32 error code is returned.

## Remarks

For **ServiceDirectoryPersistentState**, the security of the directory is set to only provide write access to the local system account and the service SID. Ensure service SIDs are enabled for any service that calls this API. For more information, see [SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info).

For a similar API that provides service state that can be shared with associated programs, see [GetSharedServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getsharedservicedirectory).

All service state directories are deleted by the service control manager once the service is uninstalled.

## See also

[RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-registerservicectrlhandlera)

[GetSharedServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getsharedservicedirectory)

[SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info)