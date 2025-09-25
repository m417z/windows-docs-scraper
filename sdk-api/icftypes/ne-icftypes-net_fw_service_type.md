# NET_FW_SERVICE_TYPE enumeration

## Description

> [!NOTE]
>The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page)Windows API is recommended.

The **NET_FW_SERVICE_TYPE** enumerated type specifies the type of service.

## Constants

### `NET_FW_SERVICE_FILE_AND_PRINT:0`

Service type is File and Print Sharing.

### `NET_FW_SERVICE_UPNP`

Service type is UPnP Framework.

### `NET_FW_SERVICE_REMOTE_DESKTOP`

Service type is Remote Desktop.

### `NET_FW_SERVICE_NONE`

Not a valid service type. This is used to indicate that a port is not part of a service.

### `NET_FW_SERVICE_TYPE_MAX`

Used for boundary checking only. Not valid for application programming.

## See also

[Windows Firewall Enumerated Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-enumerated-types)

[Windows Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-reference)