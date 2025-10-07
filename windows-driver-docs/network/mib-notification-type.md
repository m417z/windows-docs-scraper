# MIB\_NOTIFICATION\_TYPE enumeration

The MIB\_NOTIFICATION\_TYPE enumeration type defines the notification type that is passed to a callback function when a notification occurs.

## Constants

- **MibParameterNotification**
A parameter was changed.

- **MibAddInstance**
A new MIB instance was added.

- **MibDeleteInstance**
An existing MIB instance was deleted.

- **MibInitialNotification**
A notification that is invoked immediately after registration for change notification completes. This initial notification does not indicate that a change occurred to a MIB instance. The purpose of this initial notification type is to provide confirmation that the callback function is properly registered.

## Remarks

The MIB\_NOTIFICATION\_TYPE enumerated type is used with the callback function that is specified in the *Callback* parameter of one of the IP Helper **Notify*Xxx*** functions to specify the notification type.

On Windows Vista and later versions of the Windows operating systems, new functions are provided to register the driver to be notified when an IPv6 or IPv4 interface changes, an IPv6 or IPv4 unicast address changes, or an IPv6 or IPv4 route changes. These registration functions require that a callback function be passed that is called when a change occurs. One of the parameters that is passed to the callback function when a notification occurs is a parameter that contains a MIB\_NOTIFICATION\_TYPE value that indicates the notification type.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**NotifyIpInterfaceChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyipinterfacechange)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**NotifyStableUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/notifystableunicastipaddresstable)

[**NotifyTeredoPortChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyteredoportchange)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)