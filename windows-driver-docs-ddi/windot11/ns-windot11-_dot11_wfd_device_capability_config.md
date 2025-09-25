# _DOT11_WFD_DEVICE_CAPABILITY_CONFIG structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The device capability configuration structure sent with an [OID_DOT11_WFD_DEVICE_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-device-capability) request.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_DEVICE_CAPABILITY_CONFIG** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_DEVICE_CAPABILITY_CONFIG_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_DEVICE_CAPABILITY_CONFIG_1 |

### `bServiceDiscoveryEnabled`

When set to TRUE, the miniport must enable Service Discovery support. The miniport must also set the Service Discovery bit in the P2P Device Capability Bitmap. If **bServiceDiscoveryEnabled** is FALSE, Service Discovery support must be disabled and the miniport must ignore all Service Discovery packets it receives.

 The system will set this to TRUE only if the miniport also sets TRUE for the **bServiceDiscoverySupported** member of [DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes). The default value for this member is FALSE.

### `bClientDiscoverabilityEnabled`

When set to TRUE, the miniport must enable Client Discoverability support. The miniport must also set the Client Discoverability bit in the P2P Device Capability Bitmap. If **bClientDiscoveryEnabled** is FALSE, Client Discoverability support must be disabled and the miniport must ignore all Client Discovery packets it receives.

The system will set this to TRUE only if the miniport also sets TRUE for the **bClientDiscoverabilitySupported** member of [DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes). The default value for this member is FALSE.

### `bConcurrentOperationSupported`

When set to TRUE, the miniport must set the Concurrent Operation bit in the P2P Device Capability Bitmask. Otherwise, the Concurrent Operation bit must be cleared. The default value for this member is TRUE.

### `bInfrastructureManagementEnabled`

When set to TRUE, the miniport must enable P2P Managed Device support. The miniport must also set the P2P Infrastructure Managed bit in the P2P Device Capability Bitmap. Otherwise, the P2P Managed Device support must be disabled.

The system will set this member to TRUE only if the miniport also sets TRUE for the **bInfrastructureManagementSupported** member of [DOT11_WFD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_attributes). The default value for this member is FALSE

### `bDeviceLimitReached`

When set to TRUE, the miniport must set the Device Limit bit of the P2P Device Capability Bitmask. Otherwise, this bit must be cleared. The default value for this member is FALSE.

### `bInvitationProcedureEnabled`

When set to TRUE, the miniport must set the P2P Invitation Procedure bit of the P2P Device Capability Bitmask. Otherwise, this bit must be cleared and the miniport must ignore all Invitation request/response packets it receives. The default value for this member is TRUE.

### `WPSVersionsEnabled`

The versions of WPS enabled for the Wi-Fi Direct Device

## Syntax

```cpp
typedef struct _DOT11_WFD_DEVICE_CAPABILITY_CONFIG {
  NDIS_OBJECT_HEADER Header;
  BOOLEAN            bServiceDiscoveryEnabled;
  BOOLEAN            bClientDiscoverabilityEnabled;
  BOOLEAN            bConcurrentOperationSupported;
  BOOLEAN            bInfrastructureManagementEnabled;
  BOOLEAN            bDeviceLimitReached;
  BOOLEAN            bInvitationProcedureEnabled;
  ULONG              WPSVersionsEnabled;
} DOT11_WFD_DEVICE_CAPABILITY_CONFIG, *PDOT11_WFD_DEVICE_CAPABILITY_CONFIG;
```