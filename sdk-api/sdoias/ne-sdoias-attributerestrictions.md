# ATTRIBUTERESTRICTIONS enumeration

## Description

The values of the
**ATTRIBUTERESTRICTIONS** enumeration type specify restrictions on how a particular attribute can be used.

## Constants

### `MULTIVALUED:0x1`

Specifies whether the attribute is multivalued.

### `ALLOWEDINPROFILE:0x2`

Specifies whether the attribute is allowed in a Network Access Policy (NAP) profile.

### `ALLOWEDINCONDITION:0x4`

Specifies whether the attribute is allowed in an NAP condition.

### `ALLOWEDINPROXYPROFILE:0x8`

Specifies whether the attribute is allowed in an NAP profile for a network request proxy.

### `ALLOWEDINPROXYCONDITION:0x10`

Specifies whether the attribute is allowed in an NAP condition for a network request proxy.

### `ALLOWEDINVPNDIALUP:0x20`

Specifies whether the attribute is allowed in a VPN dialup connection.

### `ALLOWEDIN8021X:0x40`

Specifies whether the attribute is allowed in an 8021x connection.

## See also

[ATTRIBUTEINFO](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeinfo)