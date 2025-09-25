# SetIfEntry function

## Description

The
**SetIfEntry** function sets the administrative status of an interface.

## Parameters

### `pIfRow` [in]

A pointer to a
[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure. The **dwIndex** member of this structure specifies the interface on which to set administrative status. The **dwAdminStatus** member specifies the new administrative status. The **dwAdminStatus** member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MIB_IF_ADMIN_STATUS_UP** | The interface is administratively enabled. |
| **MIB_IF_ADMIN_STATUS_DOWN** | The interface is administratively disabled. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and later under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned on Windows Vista and later if the network interface specified by the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure pointed to by the *pIfRow* parameter could not be found. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pIfRow* parameter, or the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) pointed to by the *pIfRow* parameter was unspecified. This error is also returned on Windows Server 2003 and earlier if the network interface specified by the **dwIndex** member of the **MIB_IFROW** structure pointed to by the *pIfRow* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned on Windows Server 2003 and earlier if no TCP/IP stack is configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **SetIfEntry** function is used to set the administrative status of an interface on a local computer.

The **dwIndex** member in the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure pointed to by the *pIfRow* parameter must be initialized to the interface index.

The **SetIfEntry** function will fail if the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) pointed to by the *pIfRow* parameter does not match an existing interface on the local computer.

On Windows Vista and later, the **SetIfEntry** function can only be called by a user logged on as a member of the Administrators group. If **SetIfEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **SetIfEntry** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

## See also

[GetIfEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getifentry)

**GetIfTable**

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)