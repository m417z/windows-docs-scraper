# NET_FW_EDGE_TRAVERSAL_TYPE enumeration

## Description

The **NET_FW_EDGE_TRAVERSAL_TYPE** enumerated type specifies the conditions under which edge traversal traffic is allowed.

## Constants

### `NET_FW_EDGE_TRAVERSAL_TYPE_DENY:0`

Edge traversal traffic is always blocked.

This is the same as setting the EdgeTraversal property using [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) to **VARIANT_FALSE**.

### `NET_FW_EDGE_TRAVERSAL_TYPE_ALLOW`

Edge traversal traffic is always allowed.

This is the same as setting the EdgeTraversal property using [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) to **VARIANT_TRUE**.

### `NET_FW_EDGE_TRAVERSAL_TYPE_DEFER_TO_APP`

Edge traversal traffic is allowed when the application sets the [IPV6_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-protection-level) socket option to **PROTECTION_LEVEL_UNRESTRICTED**. Otherwise, it is blocked.

### `NET_FW_EDGE_TRAVERSAL_TYPE_DEFER_TO_USER`

The user is prompted whether to allow edge traversal traffic when the application sets the IPV6_PROTECTION_LEVEL socket option to **PROTECTION_LEVEL_UNRESTRICTED**. If the user chooses to allow edge traversal traffic, the rule is modified to defer to the application's settings.

If the application has not set the IPV6_PROTECTION_LEVEL socket option to **PROTECTION_LEVEL_UNRESTRICTED**, edge traversal traffic is blocked.

In order to use this option, the firewall rule must have both the application path and protocol scopes specified. This option cannot be used if port(s) are defined.

## Remarks

 In order for Windows Firewall to dynamically allow edge traversal traffic, the application must use the [IPV6_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-protection-level) socket option on the listening socket
and set it to **PROTECTION_LEVEL_UNRESTRICTED** only in the cases where edge traversal traffic should be allowed. The Windows Firewall rule added for the application must then set
its edge traversal option to **NET_FW_EDGE_TRAVERSAL_TYPE_DEFER_TO_APP** or **NET_FW_EDGE_TRAVERSAL_TYPE_DEFER_TO_USER**.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)

[IPV6_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-protection-level)

[Windows Firewall with Advanced Security Enumerated Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-with-advanced-security-enumerated-types)

[Windows Firewall with Advanced Security Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-with-advanced-security-reference)