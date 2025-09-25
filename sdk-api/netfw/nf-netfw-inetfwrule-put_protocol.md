# INetFwRule::put_Protocol

## Description

Specifies the IP protocol of this rule.

This property is read/write.

## Parameters

## Remarks

This property is optional.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

The **Protocol** property must be set before the [LocalPorts](https://learn.microsoft.com/windows/desktop/api/netfw/nf-netfw-inetfwrule-get_localports) or [RemotePorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwrule-get_remoteports) properties or an error will be returned.

A list of protocol numbers is available at the [IANA website](https://www.iana.org/assignments/protocol-numbers/protocol-numbers.xml).

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)