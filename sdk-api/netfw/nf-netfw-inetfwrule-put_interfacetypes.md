# INetFwRule::put_InterfaceTypes

## Description

Specifies the list of interface types for which the rule applies.

This property is read/write.

## Parameters

## Remarks

This property is optional.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

Acceptable values for this property are "RemoteAccess", "Wireless", "Lan", and "All". If more than one interface type is specified, the strings must be separated by a comma.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)