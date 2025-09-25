# WNV_PROVIDER_ADDRESS_CHANGE_PARAM structure

## Description

Specifies the provider address's DAD (duplicate address detection) status change, which causes the Windows Network Virtualization (WNV) driver to generate a **WnvObjectChangeType** notification that specifies the **WnvProviderAddressType** object type containing this structure.

## Members

### `PAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the provider address.

### `PA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The IP address object for the provider address, which is the matching IP address used on the physical network for the customer address.

### `AddressState`

Type: **[NL_DAD_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568758(v=vs.85))**

A value of the [NL_DAD_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568758(v=vs.85)) enumeration that represents the new DAD state. Duplicate address detection is applicable to both IPv4 and IPv6 addresses.

| Value | Meaning |
| --- | --- |
| **IpDadStateInvalid**<br><br>0 | The DAD state is not valid. |
| **IpDadStateTentative**<br><br>1 | The DAD state is tentative. |
| **IpDadStateDuplicate**<br><br>2 | A duplicate IP address has been detected. |
| **IpDadStateDeprecated**<br><br>3 | The IP address has been deprecated. |
| **IpDadStatePreferred**<br><br>4 | The IP address is the preferred address. |

## Remarks

For a detailed description of network virtualization concepts and terminology, refer to [Hyper-V Network Virtualization Overview](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/jj134230(v=ws.11)).

## See also

[WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type)

[WNV_OBJECT_CHANGE_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_change_param)

[WNV_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_object_type)