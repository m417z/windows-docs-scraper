# SCOPE_LEVEL enumeration

## Description

The **SCOPE_LEVEL** enumeration is used with the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure to identify scope levels for IPv6 addresses.

## Constants

### `ScopeLevelInterface:1`

The scope is interface-level.

### `ScopeLevelLink:2`

The scope is link-level.

### `ScopeLevelSubnet:3`

The scope is subnet-level.

### `ScopeLevelAdmin:4`

The scope is admin-level.

### `ScopeLevelSite:5`

The scope is site-level.

### `ScopeLevelOrganization:8`

The scope is organization-level.

### `ScopeLevelGlobal:14`

The scope is global.

### `ScopeLevelCount:16`

## Remarks

The **SCOPE_LEVEL** enumeration is used in the **ZoneIndices** member of the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure.

On Windows Vista and later as well as on the Microsoft Windows Software Development Kit (SDK), the organization of header files has changed and the **SCOPE_LEVEL** enumeration type is defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

## See also

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)