# INetFwRule::get_LocalPorts

## Description

Specifies the list of local ports for this rule.

This property is read/write.

## Parameters

## Remarks

This property is optional.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

The [Protocol](https://learn.microsoft.com/windows/desktop/api/netfw/nf-netfw-inetfwrule-get_protocol) property must be set before the **LocalPorts** property or an error will be returned.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)