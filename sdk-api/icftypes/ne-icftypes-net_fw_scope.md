# NET_FW_SCOPE enumeration

## Description

> [!NOTE]
>The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page)Windows API is recommended.

The
**NET_FW_SCOPE** enumerated type specifies the scope of addresses from which a port can listen.

## Constants

### `NET_FW_SCOPE_ALL:0`

Scope is all.

### `NET_FW_SCOPE_LOCAL_SUBNET`

Scope is local subnet only.

### `NET_FW_SCOPE_CUSTOM`

Scope is custom.

### `NET_FW_SCOPE_MAX`

Used for boundary checking only. Not valid for application programming.

## See also

[Windows Firewall Enumerated Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-enumerated-types)

[Windows Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-reference)