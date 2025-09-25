# Dhcpv6ReleasePrefix function

## Description

The [Dhcpv6ReleasePrefix](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpv6csdk/nf-dhcpv6csdk-dhcpv6requestprefix) function releases a prefix previously acquired with the **Dhcpv6RequestPrefix** function.

## Parameters

### `adapterName` [in]

Name of the adapter on which the PD request must be sent.

### `classId` [in]

Pointer to a [DHCPV6CAPI_CLASSID](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6capi_classid) structure that contains the binary ClassId information to use to send on the wire.

**Note** DHCPv6 Option Code 15 (0x000F) is not supported by this API. Typically, the User Class option is used by a client to identify the type or category of user or application it represents. A server selects the configuration information for the client based on the classes identified in this option.

### `leaseInfo` [in]

Pointer to a [DHCPV6CAPIPrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure that is used to release the prefix.

## Return value

Returns ERROR_SUCCESS upon successful completion.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Returned if one of the following conditions are true:<br><br>* *AdapterName* is **NULL**. Or no adapter is found with the GUID specified.<br>* *prefixleaseInfo* is **NULL**. |
| **ERROR_INVALID_NAME** | The *AdapterName* is not in the correct format. It should be in this format: {00000000-0000-0000-0000-000000000000}. |

## Remarks

Release messages sent as the result of the call to this function must contain the following values for the **T1** and **T2** fields of the [DHCPV6CAPIPrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure supplied in the *prefixleaseInfo* parameter:

* **T1**: the renewal time for the prefix, in seconds specified as absolute time values.
* **T2**: the rebind time of the prefix, in seconds specified as absolute time values.