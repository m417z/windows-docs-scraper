# WNV_REDIRECT_PARAM structure

## Description

Specifies the parameters of the event (receiving an incoming Internet Control Message Protocol
redirect packet) that causes the Windows Network Virtualization (WNV) driver to generate a **WnvRedirectType** notification. If there is a pending call to the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function of this type, the WNV driver fills the buffer that is passed in the *NotificationParam* argument's [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure with one or more instances of this structure and completes the **WnvRequestNotification** function call.

## Members

### `CAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the customer address.

### `PAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the original provider address.

### `NewPAFamily`

Type: **ADDRESS_FAMILY**

The address family (**AF_INET** or **AF_INET6**) for the new provider address.

### `VirtualSubnetId`

Type: **ULONG**

The identifier of a customer virtual subnet. This value ranges from 4096 (0x00001000) to 16777214 (0x00FFFFFE).

### `CA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The IP address object for the customer address, which is the IP address configured on the virtual machine for network virtualization.

### `PA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The IP address object for the provider address, which is the matching IP address used on the physical network for the customer address.

### `NewPA`

Type: **[WNV_IP_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_ip_address)**

The updated provider address when a virtual machine is migrated from one host to another.

## Remarks

Hyper-V Network Virtualization uses an Internet Control Message Protocol
(ICMP) redirect message to indicate a change in the virtual machine's provider address in the case of a live migration of a virtual machine.

For a detailed description of network virtualization concepts and terminology, refer to [Hyper-V Network Virtualization Overview](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/jj134230(v=ws.11)).

## See also

[WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type)