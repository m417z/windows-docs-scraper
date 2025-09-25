# DeleteAnycastIpAddressEntry function

## Description

The
**DeleteAnycastIpAddressEntry** function deletes an existing anycast IP address entry on the local computer.

## Parameters

### `Row` [in]

A pointer to a
[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure entry for an existing anycast IP address entry to delete from the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) pointed to by the *Row* parameter was not set to a valid unicast IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_ANYCASTIPADDRESS_ROW** pointed to by the *Row* parameter were unspecified. |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) pointed to by the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address was specified in the **Address** member [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address was specified in the **Address** member . |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **DeleteAnycastIpAddressEntry** function is defined on Windows Vista and later.

The **DeleteAnycastIpAddressEntry** function is used to delete an existing [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure entry on the local computer.

On input, the **Address** member in the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure pointed to by the *Row* parameter must be set to a valid unicast IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_ANYCASTIPADDRESS_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

If the function is successful, the existing IP address represented by the *Row* parameter was deleted.

The [GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable) function can be called to enumerate the anycast IP address entries on a local computer. The [GetAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddressentry) function can be called to retrieve a specific existing anycast IP address entry.

The **DeleteAnycastIpAddressEntry** function can only be called by a user logged on as a member of the Administrators group. If **DeleteAnycastIpAddressEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[CreateAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createanycastipaddressentry)

[GetAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddressentry)

[GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row)

[MIB_ANYCASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_table)