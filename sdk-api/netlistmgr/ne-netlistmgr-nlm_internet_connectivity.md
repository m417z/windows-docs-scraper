# NLM_INTERNET_CONNECTIVITY enumeration

## Description

The **NLM_INTERNET_CONNECTIVITY** enumeration defines a set of flags that provide additional data for IPv4 or IPv6 network connectivity.

## Constants

### `NLM_INTERNET_CONNECTIVITY_WEBHIJACK:0x1`

Indicates that the detected network is a hotspot. For example, when connected to a coffee Wi-Fi hotspot network and the local HTTP traffic is being redirected to a captive portal, this flag will be set.

### `NLM_INTERNET_CONNECTIVITY_PROXIED:0x2`

Indicates that the detected network has a proxy configuration. For example, when connected to a corporate network using a proxy for HTTP access, this flag will be set.

### `NLM_INTERNET_CONNECTIVITY_CORPORATE:0x4`

Indicates that the machine is configured for Direct Access and that access to the corporate domain network, for which Direct Access was previously configured, has been detected.

## Remarks

These connectivity flags can be retrieved by querying for the *NA_InternetConnectivityV4* or *NA_InternetConnectivityV6* properties using the **IPropertyBag** interface for an [INetwork](https://learn.microsoft.com/windows/win32/api/netlistmgr/nn-netlistmgr-inetwork) or [INetworkConnection](https://learn.microsoft.com/windows/win32/api/netlistmgr/nn-netlistmgr-inetworkconnection) interface.

## See also

[INetwork](https://learn.microsoft.com/windows/win32/api/netlistmgr/nn-netlistmgr-inetwork)

[INetworkConnection](https://learn.microsoft.com/windows/win32/api/netlistmgr/nn-netlistmgr-inetworkconnection)

[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)