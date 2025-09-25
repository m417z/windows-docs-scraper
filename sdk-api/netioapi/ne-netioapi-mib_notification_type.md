# MIB_NOTIFICATION_TYPE enumeration

## Description

The **MIB_NOTIFICATION_TYPE** enumeration defines the notification type passed to a callback function when a notification occurs.

## Constants

### `MibParameterNotification`

A parameter was changed.

### `MibAddInstance`

A new MIB instance was added.

### `MibDeleteInstance`

An existing MIB instance was deleted.

### `MibInitialNotification`

A notification that is invoked immediately after registration for change notification completes. This initial notification does not indicate a change occurred to a MIB instance. The purpose of this initial notification type is to provide confirmation that the callback function is properly registered.

## Remarks

The **MIB_NOTIFICATION_TYPE** enumeration is defined on Windows Vista and later.

On Windows Vista and later, new functions are provided to register to be notified when an IPv6 or IPv4 interface changes, a IPv6 or IPv4 unicast address changes, or an IPv6 or IPv4 route changes. These registration functions require a callback function be passed that is called when a change occurs. One of the parameters passed to the callback function when a notification occurs is a parameter containing a **MIB_NOTIFICATION_TYPE** that indicates the notification type.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)