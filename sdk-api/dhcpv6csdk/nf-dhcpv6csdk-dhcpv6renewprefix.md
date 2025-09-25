# Dhcpv6RenewPrefix function

## Description

The **Dhcpv6RenewPrefix** function renews a prefix previously acquired with the [Dhcpv6RequestPrefix](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpv6csdk/nf-dhcpv6csdk-dhcpv6requestprefix) function.

## Parameters

### `adapterName` [in]

GUID of the adapter on which the prefix renewal must be sent.

### `pclassId` [in]

Pointer to a [DHCPV6CAPI_CLASSID](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6capi_classid) structure that contains the binary ClassId information to send on the wire. This parameter is can be **NULL**.

**Note** DHCPv6 Option Code 15 (0x000F) is not supported by this API. Typically, the User Class option is used by a client to identify the type or category of user or application it represents. A server selects the configuration information for the client based on the classes identified in this option.

### `prefixleaseInfo` [in, out]

Pointer to a [DHCPV6PrefixLeaseInformation](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefixleaseinformation) structure that contains the prefix lease information.

### `pdwTimeToWait` [out]

Contains the number of seconds a requesting application needs to wait before calling the **Dhcpv6RenewPrefix** function to renew its acquired prefixes. A value of 0xFFFFFFFF indicates that the application does not need to renew its lease.

### `bValidatePrefix` [in]

Specifies to the DHCPv6 client whether or not to send a REBIND in order to validate the prefix bindings. **TRUE** indicates that a REBIND is required. **FALSE** indicates RENEW is required.

## Return value

Returns ERROR_SUCCESS upon successful completion.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Returned if one of the following conditions are true:<br><br>* *AdapterName* is **NULL**. Or no adapter is found with the GUID specified.<br>* *prefixleaseInfo* is **NULL**.<br>* *pdwTimeToWait* is **NULL**. |
| **ERROR_MORE_DATA** | Returned if the API responds with more prefixes than there is memory allocated. |
| **ERROR_INVALID_NAME** | The *AdapterName* is not in the correct format. It should be in this format: {00000000-0000-0000-0000-000000000000}. |