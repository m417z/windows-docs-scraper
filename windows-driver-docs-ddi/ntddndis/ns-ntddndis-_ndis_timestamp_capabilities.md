# _NDIS_TIMESTAMP_CAPABILITIES structure

## Description

The **NDIS_TIMESTAMP_CAPABILITIES** structure describes the combined timestamping capabilities of a network interface card (NIC) and miniport driver.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_TIMESTAMP_CAPABILITIES** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.

* Set the **Revision** member to **NDIS_TIMESTAMP_CAPABILITIES_REVISION_1**.

* Set the **Size** member to **NDIS_SIZEOF_TIMESTAMP_CAPABILITIES_REVISION_1**.

### `HardwareClockFrequencyHz`

This field contains the nominal frequency of the hardware clock that the NIC uses for timestamping, rounded off to the nearest integer in Hertz units.

### `CrossTimestamp`

A value of **TRUE** indicates that the miniport/hardware combination is capable of generating a hardware cross timestamp. A value of **FALSE** indicates this capability does not exist. A cross timestamp is the set of a NIC hardware timestamp and system timestamp(s) obtained very close to each other. The miniport driver handles the [OID_TIMESTAMP_GET_CROSSTIMESTAMP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-timestamp-get-crosstimestamp) OID to generate a cross timestamp.

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

### `TimestampFlags`

An [**NDIS_TIMESTAMP_CAPABILITY_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_timestamp_capability_flags) structure that represents the NIC's timestamping capabilities in various contexts.

## Remarks

Miniport drivers use the **NDIS_TIMESTAMP_CAPABILITIES** structure with the [**NDIS_STATUS_TIMESTAMP_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-timestamp-capability) status indication to report the NIC's hardware timestamping capabilities and the miniport driver's software timestamping capabilities to NDIS and overlying drivers.

> [!NOTE]
> An implementation must support hardware timestamps and cross timestamps. Supporting software timestamps is optional.

Miniport drivers use the **NDIS_TIMESTAMP_CAPABILITIES** structure with the [**NDIS_STATUS_TIMESTAMP_CURRENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-timestamp-current-config) status indication to report which timestamping capabilities are currently enabled.

For more information, see [Reporting timestamping capabilities and current configuration](https://learn.microsoft.com/windows-hardware/drivers/network/reporting-timestamping-capabilities).

## See also

[**NDIS_TIMESTAMP_CAPABILITY_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_timestamp_capability_flags)

[**NDIS_STATUS_TIMESTAMP_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-timestamp-capability)

[**NDIS_STATUS_TIMESTAMP_CURRENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-timestamp-current-config)

[OID_TIMESTAMP_GET_CROSSTIMESTAMP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-timestamp-get-crosstimestamp)

[**MiniportInitializeEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[Reporting timestamping capabilities and current configuration](https://learn.microsoft.com/windows-hardware/drivers/network/reporting-timestamping-capabilities)