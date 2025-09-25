# SetUnicastIpAddressEntry function

## Description

The
[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function sets the properties of an existing unicast IP address entry on the local computer.

## Parameters

### `Row` [in]

A pointer to a
[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry for an existing unicast IP address entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter was not set to a valid unicast IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_UNICASTIPADDRESS_ROW** pointed to by the *Row* parameter were unspecified.<br><br>This error is also returned for other errors in the values set for members in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure. These errors include the following: if the **ValidLifetime** member is less than the **PreferredLifetime** member, if the **PrefixOrigin** member is set to **IpPrefixOriginUnchanged** and the **SuffixOrigin** is the not set to **IpSuffixOriginUnchanged**, if the **PrefixOrigin** member is not set to **IpPrefixOriginUnchanged** and the **SuffixOrigin** is set to **IpSuffixOriginUnchanged**, if the **PrefixOrigin** member is not set to a value from the **NL_PREFIX_ORIGIN** enumeration, if the **SuffixOrigin** member is not set to a value from the **NL_SUFFIX_ORIGIN** enumeration, or if the **OnLinkPrefixLength** member is set to a value greater than the IP address length, in bits (32 for an unicast IPv4 address or 128 for an unicast IPv6 address). |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address was specified in the **Address** member [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter or no IPv6 stack is on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function is defined on Windows Vista and later.

The [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) function is normally used to retrieve an existing [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry to be modified. An application can then change the
members in the **MIB_UNICASTIPADDRESS_ROW** entry it wishes to modify, and then call the [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function.

An application may call the [InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry) function to initialize the members of a
[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry with default values before making changes. However, the application would normally save either the **InterfaceLuid** or **InterfaceIndex** member before calling **InitializeUnicastIpAddressEntry** and restore one of these members after the call.

The **Address** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter must be initialized to a valid unicast IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_UNICASTIPADDRESS_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

If the **OnLinkPrefixLength** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter is set to 255, then [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) will set the unicast IP address properties so that the **OnLinkPrefixLength** member is equal to the length of the IP address. So for a unicast IPv4 address, the **OnLinkPrefixLength** is set to 32 and the **OnLinkPrefixLength** is set to 128 for a unicast IPv6 address. If this would result in the incorrect subnet mask for an IPv4 address or the incorrect link prefix for an IPv6 address, then the application should set this member to the correct value before calling **SetUnicastIpAddressEntry**.

The **DadState**, **ScopeId**, and **CreationTimeStamp** members of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* are ignored when the [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function is called. These members are set by the network stack and cannot be changed using the **SetUnicastIpAddressEntry** function. The **ScopeId** member is automatically determined by the interface on which the address was added.

The [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function can only be called by a user logged on as a member of the Administrators group. If **SetUnicastIpAddressEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteunicastipaddressentry)

[GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry)

[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)