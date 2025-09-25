# NET_FW_IP_VERSION enumeration

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

The
**NET_FW_IP_VERSION** enumerated type specifies the IP version for a port.

## Constants

### `NET_FW_IP_VERSION_V4:0`

The port supports IPv4.

### `NET_FW_IP_VERSION_V6`

The port supports IPv6.

### `NET_FW_IP_VERSION_ANY`

The port supports either version of IP.

### `NET_FW_IP_VERSION_MAX`

This value is used for boundary checking only and is not valid for application programming.

## See also

[Windows Firewall Enumerated Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-enumerated-types)

[Windows Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-reference)