# QueryServiceConfig2W function

## Description

Retrieves the optional configuration parameters of the specified service.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function and must have the **SERVICE_QUERY_CONFIG** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwInfoLevel` [in]

The configuration information to be queried. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_CONFIG_DELAYED_AUTO_START_INFO**<br><br>3 | The *lpInfo* parameter is a pointer to a [SERVICE_DELAYED_AUTO_START_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_delayed_auto_start_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_DESCRIPTION**<br><br>1 | The *lpBuffer* parameter is a pointer to a [SERVICE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_descriptiona) structure. |
| **SERVICE_CONFIG_FAILURE_ACTIONS**<br><br>2 | The *lpBuffer* parameter is a pointer to a [SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsa) structure. |
| **SERVICE_CONFIG_FAILURE_ACTIONS_FLAG**<br><br>4 | The *lpInfo* parameter is a pointer to a [SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_PREFERRED_NODE**<br><br>9 | The *lpInfo* parameter is a pointer to a [SERVICE_PREFERRED_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preferred_node_info) structure.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_PRESHUTDOWN_INFO**<br><br>7 | The *lpInfo* parameter is a pointer to a [SERVICE_PRESHUTDOWN_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preshutdown_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO**<br><br>6 | The *lpInfo* parameter is a pointer to a [SERVICE_REQUIRED_PRIVILEGES_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_required_privileges_infoa) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_SERVICE_SID_INFO**<br><br>5 | The *lpInfo* parameter is a pointer to a [SERVICE_SID_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_sid_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_TRIGGER_INFO**<br><br>8 | The *lpInfo* parameter is a pointer to a [SERVICE_TRIGGER_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger_info) structure.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_LAUNCH_PROTECTED**<br><br>12 | The *lpInfo* parameter is a pointer a [SERVICE_LAUNCH_PROTECTED_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_launch_protected_info) structure.<br><br>**Note** This value is supported starting with Windows 8.1. |

### `lpBuffer` [out, optional]

A pointer to the buffer that receives the service configuration information. The format of this data depends on the value of the *dwInfoLevel* parameter.

The maximum size of this array is 8K bytes. To determine the required size, specify **NULL** for this parameter and 0 for the *cbBufSize* parameter. The function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**. The *pcbBytesNeeded* parameter receives the needed size.

### `cbBufSize` [in]

The size of the structure pointed to by the *lpBuffer* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes required to store the configuration information, if the function fails with **ERROR_INSUFFICIENT_BUFFER**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Others can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the **SERVICE_QUERY_CONFIG** access right. |
| **ERROR_INSUFFICIENT_BUFFER** | There is more service configuration information than would fit into the *lpBuffer* buffer. The number of bytes required to get all the information is returned in the *pcbBytesNeeded* parameter. Nothing is written to *lpBuffer*. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

## Remarks

The
**QueryServiceConfig2** function returns the optional configuration information stored in the service control manager database for the specified service. You can change this configuration information by using the
[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) function.

You can change and query additional configuration information using the
[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga) and
[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga) functions, respectively.

#### Examples

For an example, see
[Querying a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/querying-a-service-s-configuration).

> [!NOTE]
> The winsvc.h header defines QueryServiceConfig2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[SERVICE_DELAYED_AUTO_START_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_delayed_auto_start_info)

[SERVICE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_descriptiona)

[SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsa)

[SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag)

[SERVICE_PRESHUTDOWN_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preshutdown_info)

[SERVICE_REQUIRED_PRIVILEGES_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_required_privileges_infoa)

[SERVICE_SID_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_sid_info)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)