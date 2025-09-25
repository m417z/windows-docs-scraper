# _DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

the **DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG** structure is included with a [OID_DOT11_WFD_GROUP_OWNER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-group-owner-capability) request. The structure contains capability settings for a Peer-to-Peer Group Owner (P2P GO).

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_GROUP_OWNER_CAPABILITY_CONFIG_1 |

### `bPersistentGroupEnabled`

If TRUE, the miniport must set the Persistent P2P Group bit of the Group Capability bitmask. Otherwise, the Persistent P2P Group bit must be cleared. The default value of this member is FALSE.

### `bIntraBSSDistributionSupported`

If TRUE, the miniport must set the Intra-BSS Distribution bit of the Group Capability bitmask. Otherwise, the Intra-BSS Distribution bit must be cleared. The default value of this member is FALSE.

### `bCrossConnectionSupported`

If TRUE, the miniport must set the Cross Connection bit of the Group Capability bitmask. Otherwise, the Cross Connection bit must be cleared. The default value of this member is FALSE.

### `bPersistentReconnectSupported`

If TRUE, the miniport must set the Persistent Reconnect bit of the Group Capability bitmask. Otherwise, the Persistent Reconnect bit must be cleared. The default value of this member is FALSE.

### `bGroupFormationEnabled`

If TRUE, the miniport must set the Group Formation bit of the Group Capability bitmask. Otherwise, the Group Formation bit must be cleared. The default value of this member is FALSE.

### `uMaximumGroupLimit`

Maximum number of P2P Clients the GO should allow. Once this limit is reached, the miniport should reject the addition of any new Clients and should set the Group Limit bit in the Group Capability bitmask. The default value for this member is same as the value reported in the **uGORoleClientTableSize** member of [DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes).

## Syntax

```cpp
typedef struct _DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG {
  NDIS_OBJECT_HEADER Header;
  BOOLEAN            bPersistentGroupEnabled;
  BOOLEAN            bIntraBSSDistributionSupported;
  BOOLEAN            bCrossConnectionSupported;
  BOOLEAN            bPersistentReconnectSupported;
  BOOLEAN            bGroupFormationEnabled;
  ULONG              uMaximumGroupLimit;
}  DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG, *PDOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG;
```

## See also

[OID_DOT11_WFD_GROUP_OWNER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-group-owner-capability)