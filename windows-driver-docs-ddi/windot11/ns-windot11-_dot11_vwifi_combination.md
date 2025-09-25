# _DOT11_VWIFI_COMBINATION structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_VWIFI_COMBINATION structure specifies the combination of 802.11 MAC entities that an 802.11
miniport driver can simultaneously support when it is virtualized.

## Members

### `Header`

The type, revision, and size of the DOT11_VWIFI_COMBINATION structure. This member is formatted as
an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_VWIFI_COMBINATION_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_VWIFI_COMBINATION).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumInfrastructure`

The number of 802.11 infrastructure stations supported. For more information, see the following
Remarks section.

### `uNumAdhoc`

The number of Adhoc Stations supported. For more information, see the following Remarks
section.

### `uNumSoftAP`

The number of Soft AP Stations supported. For more information, see the following Remarks
section.

## Syntax

```cpp
typedef struct _DOT11_VWIFI_COMBINATION {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumInfrastructure;
  ULONG              uNumAdhoc;
  ULONG              uNumSoftAP;
} DOT11_VWIFI_COMBINATION, *PDOT11_VWIFI_COMBINATION;
```

## Remarks

Starting with Windows 7, the 802.11 miniport driver must only report one or more of the following
combination of member values.

* **uNumInfrastructure** = 1
* **uNumAdhoc** = 0
* **uNumSoftAP** = 1

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)