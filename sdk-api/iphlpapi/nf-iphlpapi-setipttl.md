# SetIpTTL function

## Description

The
**SetIpTTL** function sets the default time-to-live (TTL) value for the local computer.

## Parameters

### `nTTL` [in]

The new TTL value for the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *nTTL* parameter is invalid. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The default TTL can also be set using the
[SetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatistics) function.

On Windows Vista and later, the **SetIpTTL** function can only be called by a user logged on as a member of the Administrators group. If **SetIpTTL** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The [SetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatistics) function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh)

[SetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatistics)

[SetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatisticsex)