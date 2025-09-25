# EnumServicesStatusExA function

## Description

Enumerates services in the specified service control manager database. The name and status of each service are provided, along with additional data based on the specified information level.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database. This handle is returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function, and must have the **SC_MANAGER_ENUMERATE_SERVICE** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `InfoLevel` [in]

The service attributes that are to be returned. Use **SC_ENUM_PROCESS_INFO** to retrieve the name and service status information for each service in the database. The *lpServices* parameter is a pointer to a buffer that receives an array of
[ENUM_SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_status_processa) structures. The buffer must be large enough to hold the structures as well as the strings to which their members point.

Currently, no other information levels are defined.

### `dwServiceType` [in]

The type of services to be enumerated. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_DRIVER**<br><br>0x0000000B | Services of type **SERVICE_KERNEL_DRIVER** and **SERVICE_FILE_SYSTEM_DRIVER**. |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | File system driver services. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | Driver services. |
| **SERVICE_WIN32**<br><br>0x00000030 | Services of type **SERVICE_WIN32_OWN_PROCESS** and **SERVICE_WIN32_SHARE_PROCESS**. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | Services that run in their own processes. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | Services that share a process with one or more other services. For more information, see [Service Programs](https://learn.microsoft.com/windows/desktop/Services/service-programs). |

### `dwServiceState` [in]

The state of the services to be enumerated. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ACTIVE**<br><br>0x00000001 | Enumerates services that are in the following states: **SERVICE_START_PENDING**, **SERVICE_STOP_PENDING**, **SERVICE_RUNNING**, **SERVICE_CONTINUE_PENDING**, **SERVICE_PAUSE_PENDING**, and **SERVICE_PAUSED**. |
| **SERVICE_INACTIVE**<br><br>0x00000002 | Enumerates services that are in the **SERVICE_STOPPED** state. |
| **SERVICE_STATE_ALL**<br><br>0x00000003 | Combines the **SERVICE_ACTIVE** and **SERVICE_INACTIVE** states. |

### `lpServices` [out, optional]

A pointer to the buffer that receives the status information. The format of this data depends on the value of the *InfoLevel* parameter.

The maximum size of this array is 256K bytes. To determine the required size, specify **NULL** for this parameter and 0 for the *cbBufSize* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_MORE_DATA**. The *pcbBytesNeeded* parameter will receive the required size.

**Windows Server 2003 and Windows XP:** The maximum size of this array is 64K bytes. This limit was increased as of Windows Server 2003 with SP1 and Windows XP with SP2.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpServices* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to return the remaining service entries, if the buffer is too small.

### `lpServicesReturned` [out]

A pointer to a variable that receives the number of service entries returned.

### `lpResumeHandle` [in, out, optional]

A pointer to a variable that, on input, specifies the starting point of enumeration. You must set this value to zero the first time the
**EnumServicesStatusEx** function is called. On output, this value is zero if the function succeeds. However, if the function returns zero and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_MORE_DATA**, this value indicates the next service entry to be read when the
**EnumServicesStatusEx** function is called to retrieve the additional data.

### `pszGroupName` [in, optional]

The load-order group name. If this parameter is a string, the only services enumerated are those that belong to the group that has the name specified by the string. If this parameter is an empty string, only services that do not belong to any group are enumerated. If this parameter is **NULL**, group membership is ignored and all services are enumerated.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following errors may be returned.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the **SC_MANAGER_ENUMERATE_SERVICE** access right. |
| **ERROR_MORE_DATA** | The buffer is too small. Not all data in the active database could be returned. The *pcbBytesNeeded* parameter contains the number of bytes required to receive the remaining entries. |
| **ERROR_INVALID_PARAMETER** | An illegal parameter value was used. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_INVALID_LEVEL** | The *InfoLevel* parameter contains an unsupported value. |
| **ERROR_SHUTDOWN_IN_PROGRESS** | The system is shutting down; this function cannot be called. |

## Remarks

If the caller does not have the **SERVICE_QUERY_STATUS** access right to a service, the service is silently omitted from the list of services returned to the client.

> [!NOTE]
> The winsvc.h header defines EnumServicesStatusEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ENUM_SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_status_processa)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Installation, Removal, and Enumeration](https://learn.microsoft.com/windows/desktop/Services/service-installation-removal-and-enumeration)