# SetIpNetEntry function

## Description

The
**SetIpNetEntry** function modifies an existing ARP entry in the ARP table on the local computer.

## Parameters

### `pArpEntry` [in]

A pointer to a
[MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) structure. The information in this structure specifies the entry to modify and the new information for the entry. The caller must specify values for all members of this structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | The *pArpEntry* parameter is **NULL**, or **SetIpNetEntry** is unable to read from the memory pointed to by *pArpEntry*, or one of the members of the [MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) structure is invalid. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

On Windows Vista and later , the **SetIpNetEntry** function can only be called by a user logged on as a member of the Administrators group. If **SetIpNetEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **SetIpNetEntry** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

## See also

[CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry)

[DeleteIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipnetentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh)