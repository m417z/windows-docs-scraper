# INetFwRule::get_EdgeTraversal

## Description

Indicates whether edge traversal is enabled or disabled for this rule.

This property is read/write.

## Parameters

## Remarks

The EdgeTraversal property indicates that specific inbound traffic is allowed to tunnel through NATs and other edge devices using the Teredo tunneling technology. In order for this setting to work correctly, the application or service with the inbound firewall rule needs to support IPv6. The primary application of this setting allows listeners on the host to be globally addressable through a Teredo IPv6 address.

New rules have the EdgeTraversal property disabled by default.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)