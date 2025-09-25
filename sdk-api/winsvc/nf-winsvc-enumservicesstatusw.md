# EnumServicesStatusW function

## Description

Enumerates services in the specified service control manager database. The name and status of each service are provided.

This function has been superseded by the
[EnumServicesStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusexa) function. It returns the same information
**EnumServicesStatus** returns, plus the process identifier and additional information for the service. In addition,
**EnumServicesStatusEx** enables you to enumerate services that belong to a specified group.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database. This handle is returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function, and must have the SC_MANAGER_ENUMERATE_SERVICE access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwServiceType` [in]

The type of services to be enumerated. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_DRIVER**<br><br>0x0000000B | Services of type SERVICE_KERNEL_DRIVER and SERVICE_FILE_SYSTEM_DRIVER. |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | File system driver services. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | Driver services. |
| **SERVICE_WIN32**<br><br>0x00000030 | Services of type SERVICE_WIN32_OWN_PROCESS and SERVICE_WIN32_SHARE_PROCESS. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | Services that run in their own processes. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | Services that share a process with one or more other services. For more information, see [Service Programs](https://learn.microsoft.com/windows/desktop/Services/service-programs). |

### `dwServiceState` [in]

The state of the services to be enumerated. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ACTIVE**<br><br>0x00000001 | Enumerates services that are in the following states: SERVICE_START_PENDING, SERVICE_STOP_PENDING, SERVICE_RUNNING, SERVICE_CONTINUE_PENDING, SERVICE_PAUSE_PENDING, and SERVICE_PAUSED. |
| **SERVICE_INACTIVE**<br><br>0x00000002 | Enumerates services that are in the SERVICE_STOPPED state. |
| **SERVICE_STATE_ALL**<br><br>0x00000003 | Combines the following states: SERVICE_ACTIVE and SERVICE_INACTIVE. |

### `lpServices` [out, optional]

A pointer to a buffer that contains an array of
[ENUM_SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_statusa) structures that receive the name and service status information for each service in the database. The buffer must be large enough to hold the structures, plus the strings to which their members point.

The maximum size of this array is 256K bytes. To determine the required size, specify NULL for this parameter and 0 for the *cbBufSize* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER. The *pcbBytesNeeded* parameter will receive the required size.

**Windows Server 2003 and Windows XP:** The maximum size of this array is 64K bytes. This limit was increased as of Windows Server 2003 with SP1 and Windows XP with SP2.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpServices* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to return the remaining service entries, if the buffer is too small.

### `lpServicesReturned` [out]

A pointer to a variable that receives the number of service entries returned.

### `lpResumeHandle` [in, out, optional]

A pointer to a variable that, on input, specifies the starting point of enumeration. You must set this value to zero the first time this function is called. On output, this value is zero if the function succeeds. However, if the function returns zero and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns ERROR_MORE_DATA, this value is used to indicate the next service entry to be read when the function is called to retrieve the additional data.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the SC_MANAGER_ENUMERATE_SERVICE access right. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter that was specified is invalid. |
| **ERROR_MORE_DATA** | There are more service entries than would fit into the *lpServices* buffer. The actual number of service entries written to *lpServices* is returned in the *lpServicesReturned* parameter. The number of bytes required to get the remaining entries is returned in the *pcbBytesNeeded* parameter. The remaining services can be enumerated by additional calls to [EnumServicesStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusa) with the *lpResumeHandle* parameter indicating the next service to read. |

## See also

[ENUM_SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_statusa)

[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa)

[EnumServicesStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusexa)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Installation, Removal, and Enumeration](https://learn.microsoft.com/windows/desktop/Services/service-installation-removal-and-enumeration)

## Remarks

> [!NOTE]
> The winsvc.h header defines EnumServicesStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).