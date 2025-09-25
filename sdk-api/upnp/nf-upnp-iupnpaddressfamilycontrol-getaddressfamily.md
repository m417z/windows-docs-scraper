# IUPnPAddressFamilyControl::GetAddressFamily

## Description

The **GetAddressFamily** method retrieves the current value of the address family flag of the Device Finder object.

## Parameters

### `pdwFlags` [out, retval]

Pointer to an integer (4-byte value) that indicates the address family.

The following values are valid.

| Value | Meaning |
| --- | --- |
| **UPNP_ADDRESSFAMILY_IPv4** | IPv4 (IP version 4) |
| **UPNP_ADDRESSFAMILY_IPv6** | IPv6 (IP version 6) |
| **UPNP_ADDRESSFAMILY_BOTH** | IPv4 and IPv6 |

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPAddressFamilyControl](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpaddressfamilycontrol)

[SetAddressFamily](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpaddressfamilycontrol-setaddressfamily)