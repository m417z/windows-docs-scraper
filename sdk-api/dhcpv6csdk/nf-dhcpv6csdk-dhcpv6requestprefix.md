# Dhcpv6RequestPrefix function

## Description

The **Dhcpv6RequestPrefix** function requests a specific prefix.

## Parameters

### `adapterName` [in]

GUID of the adapter on which the prefix request must be sent.

### `pclassId` [in]

Pointer to a [DHCPV6CAPI_CLASSID](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6capi_classid) structure that contains the binary ClassId information to send on the wire. This parameter is optional.

**Note** DHCPv6 Option Code 15 (0x000F) is not supported by this API. Typically, the User Class option is used by a client to identify the type or category of user or application it represents. A server selects the configuration information for the client based on the classes identified in this option.

### `prefixleaseInfo` [in, out]

Pointer to a [DHCPV6PrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure that contains the prefix lease information.

The following members of the [DHCPV6PrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure must follow these guidelines.

| [DHCPV6PrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) member | Consideration |
| --- | --- |
| **nPrefixes** | Must contain a maximum value of 10. The caller should have the memory allocated in the **prefixArray** member based on the number of prefixes specified. |
| **iaid** | A unique positive number assigned to this member. This same value should be reused if this function is called again.This mandatory value must be set by the calling application. |
| **ServerIdLen** | Must contain a maximum value of 128. The caller must have the memory allocated in the **ServerId** member based on the specified **ServerIdLen** value. |

The caller must follow these considerations when assigning the values of the **nPrefixes**, **iaid**, and **ServerIdLen** members of the [DHCPV6PrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure. Based on these values, memory must also be properly allocated to the **ServerId** and **PrefixArray** members before the **Dhcpv6RequestPrefix** function is called.

### `pdwTimeToWait` [out]

Contains the number of seconds a requesting application needs to wait before calling the [Dhcpv6RenewPrefix](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpv6csdk/nf-dhcpv6csdk-dhcpv6renewprefix) function to renew its acquired prefixes. A value of 0xFFFFFFFF indicates that the application does not need to renew its lease.

## Return value

Returns ERROR_SUCCESS upon successful completion.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The value of the **nPrefixes** or the **ServerIdLen** member specified is less than the number of prefixes available from the server or the available server ID length. Increase the **nPrefixes** or the **ServerIdLen** member and make sure the corresponding memory has been allocated properly before calling the [Dhcpv6RequestPrefix](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpv6csdk/nf-dhcpv6csdk-dhcpv6requestprefix) function again. |
| **ERROR_INVALID_PARAMETER** | Returned if one of the following conditions are true:<br><br>* *AdapterName* is **NULL**. Or no adapter is found with the GUID specified.<br>* *prefixleaseInfo* is **NULL**.<br>* *pdwTimeToWait* is **NULL**.<br>* The **iaid** member of the *prefixleaseInfo* is zero. |
| **ERROR_INVALID_NAME** | The *AdapterName* is not in the correct format. It should be in this format: {00000000-0000-0000-0000-000000000000}. |