## Description

The **NDIS_QOS_OFFLOAD_CAPABILITIES** structure specifies the hardware and current Hardware Quality of Service (QoS) offload capabilities of a miniport adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_OFFLOAD_CAPABILITIES** structure. This member is formatted as an [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT.

The driver must set the **Revision** member of **Header** to NDIS_QOS_OFFLOAD_CAPABILITIES_REVISION_2 to specify the version of the **NDIS_QOS_OFFLOAD_CAPABILITIES** structure.

The driver must set the **Size** member to NDIS_SIZEOF_QOS_OFFLOAD_CAPABILITIES_REVISION_2.

### `Flags`

This field is not used in NDIS_QOS_OFFLOAD_CAPABILITIES_REVISION_2. The driver must set this member to **zero**.

### `SupportedSqTypes`

A ULONG value that contains a bitwise OR of flags. These flags specify the type of NDIS QoS Scheduler Queues (SQs) that the miniport adapter supports. The following flags are defined:

#### NDIS_QOS_OFFLOAD_CAPS_STANDARD_SQ

If this flag is set, the miniport adapter supports standard SQs.

### `TransmitCapSupported`

An array of BOOLEAN values that specify whether the miniport adapter supports transmit bandwidth caps for each traffic class (TC). For more information, see [NDIS QoS Traffic Classes](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classes).

### `TransmitReservationSupported`

An array of BOOLEAN values that specify whether the miniport adapter supports transmit bandwidth reservations for each TC.

### `ReceiveCapSupported`

An array of BOOLEAN values that specify whether the miniport adapter supports receive bandwidth caps for each TC.

### `TransmitGftCapSupported`

Reserved for future use.

### `ReceiveGftCapSupported`

Reserved for future use.

### `TcSupportedTable`

An array of BOOLEAN values that specify whether the miniport adapter supports rate limits for each TC.

### `NumStandardSqsSupported`

A ULONG value that contains the maximum number of standard SQs that can be created on the miniport adapter.

### `NumGftSqsSupported`

For forward compatibility, the miniport driver must set this field to **zero** when responding to the OS query.

### `ReservationGranularitySupported`

A ULONG value that contains the scheduling granularity that the NIC can support for transmit reservations. For example, if the NIC can support at most a 1:10000 ratio between effective queues, this value should be 10000. This value is purely informational. A NIC may be asked to schedule queues with ratios between reservation values that exceed this granularity. In this case, the result should be a best approximation.

### `MaxNumSqInputs`

A ULONG value that contains the maximum number of vPorts that can be associated with an SQ.

### `CrossTcTransmitMaxCapSupported`

If **TRUE**, the miniport adapter supports a single transmit cap value for traffics across multiple TCs.

## Remarks

The **NDIS_QOS_OFFLOAD_CAPABILITIES** structure is returned in OID query requests [OID_QOS_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-hardware-capabilities) and [OID_QOS_OFFLOAD_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-current-capabilities).

## See also

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_QOS_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-hardware-capabilities)

[OID_QOS_OFFLOAD_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-current-capabilities)

[NDIS QoS Traffic Classes](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classes)