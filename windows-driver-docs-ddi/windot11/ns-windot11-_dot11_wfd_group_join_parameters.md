# _DOT11_WFD_GROUP_JOIN_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_GROUP_JOIN_PARAMETERS** structure is included with an [OID_DOT11_WFD_GROUP_JOIN_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-group-join-parameters) request. The structure contains startup parameters for a Client.

## Members

### `Header`

The type, revision, and size of the **DOT11_WFD_GROUP_JOIN_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_ GROUP_JOIN_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_GROUP_JOIN_PARAMETERS_REVISION_1 |

### `GOOperatingChannel`

This channel on which the Group Owner (GO) may operate the group. This channel information was received by the Client in a GO Negotiation or Invitation exchange. The miniport must also be able to handle the group operating on a channel different than specified. The miniport must ensure regulatory compliance when joining the group.

### `GOConfigTime`

The configuration time allowed for the GO to start. This time-out is received by the Client in a GO Negotiation or Invitation exchange.

### `bInGroupFormation`

If set to TRUE, special handling of [OID_DOT11_WFD_CONNECT_TO_GROUP_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-connect-to-group-request) is required. The miniport must not attempt to connect until it receives a probe response or beacon from the GO with the Group Formation field set to 1. Otherwise, no connect delay is necessary.

### `bWaitForWPSReady`

If set to TRUE, special handling of [OID_DOT11_WFD_CONNECT_TO_GROUP_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-connect-to-group-request) is required. The miniport must not attempt to connect until it receives a probe response or beacon from the GO with the Selected Registrar WPS attribute set to TRUE and the Group Formation field set to the value indicated by **bInGroupFormation**. Otherwise, the Selected Registrar attribute should be ignored.

## Syntax

```cpp
typedef struct _DOT11_WFD_GROUP_JOIN_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_WFD_CHANNEL  GOOperatingChannel;
  ULONG              GOConfigTime;
  BOOLEAN            bInGroupFormation;
  BOOLEAN            bWaitForWPSReady;
} DOT11_WFD_GROUP_JOIN_PARAMETERS, *PDOT11_WFD_GROUP_JOIN_PARAMETERS;
```

## See also

[OID_DOT11_WFD_GROUP_JOIN_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-group-join-parameters)