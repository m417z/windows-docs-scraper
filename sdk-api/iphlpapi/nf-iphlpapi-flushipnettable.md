# FlushIpNetTable function

## Description

The
**FlushIpNetTable** function deletes all ARP entries for the specified interface from the ARP table on the local computer.

## Parameters

### `dwIfIndex` [in]

The index of the interface for which to delete all ARP entries.

## Return value

The function returns **NO_ERROR** (zero) if the function is successful.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. This error is returned if the *dwIfIndex* parameter is invalid. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

To retrieve the ARP table, call the [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) function.

On Windows Vista and later, the **FlushIpNetTable** function can only be called by a user logged on as a member of the Administrators group. If **FlushIpNetTable** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista and later lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** This function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

## See also

[CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry)

**DeleteIpNetEntry**

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)