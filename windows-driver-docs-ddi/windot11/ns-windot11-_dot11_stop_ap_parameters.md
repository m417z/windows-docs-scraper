# _DOT11_STOP_AP_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_STOP_AP_PARAMETERS structure specifies the reason why the NIC has stopped an 802.11 access
point (AP).

## Members

### `Header`

The type, revision, and size of the DOT11_STOP_AP_PARAMETERS structure. This member is formatted
as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_STOP_AP_PARAMETERS_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_STOP_AP_PARAMETERS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ulReason`

The reason why the NIC stopped the AP. An IHV can supply the following range of values:

#### DOT11_STOP_AP_REASON_AP_ACTIVE

The miniport driver determined that an AP is already active on another 802.11 MAC entity for
this physical wireless LAN adapter.

#### DOT11_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE

The miniport driver determined that no valid operating frequency is available.

#### DOT11_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE

The miniport driver determined that no good operating channel is available.

#### DOT11_STOP_AP_REASON_IHV_END

The end value of possible IHV-specified reasons.

#### DOT11_STOP_AP_REASON_IHV_START

The start value of possible IHV-specified reasons.

If the value of
**ulReason** is in the range of DOT11_STOP_AP_REASON_IHV_START and DOT11_STOP_AP_REASON_IHV_END,
inclusive, the operating system takes no action.

## Syntax

```cpp
typedef struct _DOT11_STOP_AP_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              ulReason;
} DOT11_STOP_AP_PARAMETERS, *PDOT11_STOP_AP_PARAMETERS;
```

## Remarks

The Native 802.11 miniport driver includes a DOT11_STOP_AP_PARAMETERS structure when the driver makes
an
[NDIS_STATUS_DOT11_STOP_AP](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-stop-ap) status
indication.

## See also

[NDIS_STATUS_DOT11_STOP_AP](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-stop-ap)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)