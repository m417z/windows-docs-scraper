# _DOT11_WFD_GROUP_START_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_GROUP_START_PARAMETERS** structure is included with an [OID_DOT11_WFD_GROUP_START_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-group-start-parameters) request. The structure contains startup parameters for a Group Owner (GO).

## Members

### `Header`

The type, revision, and size of the **DOT11_WFD_GROUP_START_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_ GROUP_START_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_GROUP_START_PARAMETERS_REVISION_1 |

### `AdvertisedOperatingChannel`

The channel information originally sent to the Client in a GO Negotiation or Invitation exchange. This is the preferred channel for starting the group. The miniport must ensure regulatory compliance when starting the Group Owner.

## Syntax

```cpp
typedef struct _DOT11_WFD_GROUP_START_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_WFD_CHANNEL  AdvertisedOperatingChannel;
} DOT11_WFD_GROUP_START_PARAMETERS, *PDOT11_WFD_GROUP_START_PARAMETERS;
```

## See also

[OID_DOT11_WFD_GROUP_START_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-group-start-parameters)