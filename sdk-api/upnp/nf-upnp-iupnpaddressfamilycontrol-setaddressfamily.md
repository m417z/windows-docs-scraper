# IUPnPAddressFamilyControl::SetAddressFamily

## Description

The **SetAddressFamily** method sets the address family flag of the Device Finder object, which uses this flag to filter the devices found.

The application sets the address family flag before starting a search. The application will be notified only about devices that have IP addresses that are of the specified address family.

## Parameters

### `dwFlags` [in]

Integer (4-byte value) that specifies the address family to be used by the Device Finder object to filter the devices found.

The following values are valid.

| Value | Meaning |
| --- | --- |
| **UPNP_ADDRESSFAMILY_IPv4** | IPv4 (IP version 4) |
| **UPNP_ADDRESSFAMILY_IPv6** | IPv6 (IP version 6) |
| **UPNP_ADDRESSFAMILY_BOTH** | IPv4 and IPv6 |

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

### Setting the Flag

The address family flag must be set at the appropriate time in order to affect the search:

* For an asynchronous search, set the address family flag prior to calling the [IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind) method.
* For a synchronous search, set the address family flag prior to calling either the [IUPnPDeviceFinder::FindByUDN](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-findbyudn) or [IUPnPDeviceFinder::FindByType](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-findbytype) method.

### Filtering the Devices Found

Scenario 1: a control point application sets the address family flag to UPNP_ADDRESSFAMILY_IPV4, and then starts a search:

* If the Device Finder discovers a device that has an IPv6 address, Device Finder will not notify the application of the device. If the same device later acquires an IPv4 address, Device Finder will notify the application of the device and provide the IPv4 address.
* If the Device Finder discovers a device that has an IPv4 address, Device Finder will notify the application of the device and provide the IPv4 address. If the same device later acquires an IPv6 address, Device Finder will not notify the application of the device's additional address.
* If Device Finder discovers a device that has both IPv4 and IPv6 addresses, it will notify the application of the device, but it will provide only the IPv4 address.
* If a device that is known to the application announces an address change, Device Finder will notify the application of the change only when the new address is an IPv4 address.
* If a device that is known to the application has both IPv4 and IPv6 addresses and Device Finder receives a bye-bye message from the device's IPv6 address, Device Finder will notify the application even though the application is aware of only the IPv4 address. In other words, if a device that is known to the application leaves the network, Device Finder will notify the application regardless of the device's address.

Scenario 2: an application sets the address family flag to UPNP_ADDRESSFAMILY_IPV6, and then starts a search:

* A similar set of rules apply as described in Scenario 1, but for the opposite address family.

Scenario 3: an application sets the address family flag to UPNP_ADDRESSFAMILY_BOTH, and then starts a search:

* If the Device Finder discovers a device that has either an IPv4 address or an IPv6 address, Device Finder will notify the application of the device and provide the address. If the same device later acquires an address that is of a different address family, Device Finder will not notify the application of the device's additional address.
* If Device Finder discovers a device that has both IPv4 and IPv6 addresses, it will notify the application of the device, but it will provide only one of the addresses, chosen randomly.
* If a device that is known to the application announces an address change, Device Finder will notify the application of the change.
* If a device that is known to the application leaves the network, Device Finder will notify the application.

## See also

[GetAddressFamily](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpaddressfamilycontrol-getaddressfamily)

[IUPnPAddressFamilyControl](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpaddressfamilycontrol)