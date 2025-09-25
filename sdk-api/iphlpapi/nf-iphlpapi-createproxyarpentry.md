# CreateProxyArpEntry function

## Description

The **CreateProxyArpEnry** function creates a Proxy Address Resolution Protocol (PARP) entry on the local computer for the specified IPv4 address.

## Parameters

### `dwAddress` [in]

The IPv4 address for which this computer acts as a proxy.

### `dwMask` [in]

The subnet mask for the IPv4 address specified in *dwAddress*.

### `dwIfIndex` [in]

The index of the interface on which to proxy ARP for the IPv4 address identified by *dwAddress*. In other words, when an ARP request for *dwAddress* is received on this interface, the local computer responds with the physical address of this interface. If this interface is of a type that does not support ARP, such as PPP, then the call fails.

## Return value

The function returns **NO_ERROR** (zero) if the function is successful.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. This error is returned if the *dwAddress* parameter is **zero** or an invalid value, one of the other parameters is invalid. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

To retrieve the ARP table, call the [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) function. To delete an existing PARP entry, call the [DeleteProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteproxyarpentry).

On Windows Vista and later, the **CreateProxyArpEnry** function can only be called by a user logged on as a member of the Administrators group. If **CreateProxyArpEnry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista and later lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** This function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

## See also

[DeleteProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteproxyarpentry)

[GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_PROXYARP](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_proxyarp)