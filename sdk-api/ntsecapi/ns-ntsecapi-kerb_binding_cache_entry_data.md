# KERB_BINDING_CACHE_ENTRY_DATA structure

## Description

Specifies the data for the binding cache entry. You must have the **SeTcbPrivilege** privilege set.

## Members

### `DiscoveryTime`

The time elapsed to find the domain controller to bind to.

### `RealmName`

The name of the realm for which to obtain a binding handle.

### `KdcAddress`

The address of the Key Distribution Center (KDC) of the server to which you want to bind.

### `AddressType`

The type of string that is contained in the **KdcAddress** member. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DS_INET_ADDRESS** | The address is a string IP address of the domain controller, for example, "\\157.55.94.74"). |
| **DS_NETBIOS_ADDRESS** | The address is a NetBIOS name of the domain controller, for example, "\\phoenix". |

### `Flags`

The domain controller flags that the caller provides. These flags are needed to pass to the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function.

### `DcFlags`

The domain controller flags. These flags are returned from the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function.

### `CacheFlags`

Flags that provide more information about the binding cache.

| Value | Meaning |
| --- | --- |
| **KERB_NO_DC_FLAGS**<br><br>0x10000000 | No flags are found for the binding cache. |

### `KdcName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that specifies the name of the KDC.