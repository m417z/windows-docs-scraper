# DhcpGetClassInfo function

## Description

The **DhcpGetClassInfo** function returns the user or vendor class information configured on a specific DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ReservedMustBeZero` [in]

Reserved. This parameter must be set to 0.

### `PartialClassInfo` [in]

[DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info) structure that contains data provided by the caller for the following members, with all other fields initialized.

* **ClassName**
* **ClassData**
* **ClassDataLength**

These fields must not be null.

### `FilledClassInfo` [out]

[DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info) structure returned after lookup that contains the complete class information.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_INVALID_PARAMETER** | The [DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info) structure provided in *PartialClassInfo* has null or zero values for one or more of the required members. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | A class name could not be found that matches the provided information. |

## Remarks

A DHCP class is a specific category of client, defined either by the vendor or by a user. An example of a vendor-defined class would be all Windows 8 clients, with Microsoft as the vendor. A user-defined class consists of those clients with specific attributes selected by a user or administrator, such as all laptops or clients that support wireless connections.

## See also

[DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info)

[DhcpCreateClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclass)