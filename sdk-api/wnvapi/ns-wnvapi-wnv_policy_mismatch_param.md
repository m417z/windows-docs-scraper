# WNV_POLICY_MISMATCH_PARAM structure

## Description

Specifies the parameters of an event (typically an incoming packet) that causes the Windows Network Virtualization (WNV) driver to generate a **WnvPolicyMismatchType** notification. As a result, the WNV driver fills the buffer that is passed in the *NotificationParam* argument's [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure with one or more instances of this structure and completes the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function call.

## Members

### `CAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the customer address.

### `PAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the provider address.

### `VirtualSubnetId`

Type: **ULONG**

The identifier of a customer virtual subnet. This value ranges from 4096 (0x00001000) to 16777214 (0x00FFFFFE).

### `CA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The IP address object for the customer address, which is the IP address configured on the virtual machine for network virtualization.

### `PA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The IP address object for the provider address, which is the matching IP address used on the physical network for the customer address.

## Remarks

For a detailed description of network virtualization concepts and terminology, see [Hyper-V Network Virtualization Overview](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/jj134230(v=ws.11)).

## See also

[WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type)