## Description

The **NDIS_QOS_SQ_PARAMETERS** structure contains the parameters of an NDIS Quality of Service (QoS) Scheduler Queue (SQ).

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_SQ_PARAMETERS** structure. This member is formatted as an [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT, the **Revision** member to NDIS_QOS_SQ_PARAMETERS_REVISION_2, and the **Size** member to NDIS_SIZEOF_QOS_SQ_PARAMETERS_REVISION_2.

### `Flags`

A ULONG value that contains a bitwise OR of flags. These flags specify the miscellaneous capabilities and attributes of the Hardware QoS Offload features that are enabled on the SQ. The following flags are defined:

#### NDIS_QOS_SQ_TRANSMIT_CAP_ENABLED

If this flag is set, transmit bandwidth caps are enabled on this SQ.

#### NDIS_QOS_SQ_TRANSMIT_RESERVATION_ENABLED

If this flag is set, transmit bandwidth reservations are enabled on this SQ.

#### NDIS_QOS_SQ_RECEIVE_CAP_ENABLED

If this flag is set, receive bandwidth caps are enabled on this SQ.

### `SqId`

An **NDIS_QOS_SQ_ID** that contains the SQ ID of this SQ. NDIS assigns this ID.

### `SqType`

An [**NDIS_QOS_SQ_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-ndis_qos_sq_type) that contains the type of this SQ. This can be **NdisQSQosSqSQTypeStandard** from the enum definition of **NDIS_QOS_SQ_TYPE**.

### `TcEnabledTable`

An array of BOOLEAN values that specify whether each traffic class (from 0 to NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES) is enabled for scheduling on this SQ.

Any traffic class (TC) for which this field is **TRUE** should be read and validated in the tables below, and is also rate limited by **CrossTcTransmitBandwidthCap**.

Any TC for which this field is **FALSE** does not participate in QoS rate limiting from **CrossTcTransmitBandwidthCap** or the per-TC tables below.

### `TcTransmitBandwidthCapTable`

An array of ULONG elements that specify transmit bandwidth caps for each TC, in Mbps. Elements are only valid if the `NDIS_QOS_SQ_TRANSMIT_CAP_ENABLED` flag is set and their corresponding element in **TcEnabledTable** is **TRUE**. An element with a value of **0** has no cap.

The NIC should queue any transmit packets on this SQ for a given TC if they exceed the rate specified in this table.

### `TcTransmitBandwidthReservationTable`

An array of ULONG elements that specify transmit bandwidth reservations for each TC, in relative values from **0** – **ULONG_MAX**. Elements are only valid if the `NDIS_QOS_SQ_TRANSMIT_RESERVATION_ENABLED` flag is set and their corresponding element in **TcEnabledTable** is **TRUE**. An element with a value of **0** means that transmit packets on this SQ/TC share the default SQ’s reservation for that TC.

The NIC should queue any transmit packets on this SQ for a given TC if other SQs require bandwidth to meet their reservation for this TC.

### `TcReceiveBandwidthCapTable`

An array of ULONG elements that specify receive bandwidth caps for each TC, in Mbps. Elements are only valid if the `NDIS_QOS_SQ_RECEIVE_CAP_ENABLED` flag is set and their corresponding element in **TcEnabledTable** is **TRUE**. An element with a value of **0** has no cap.

This is an optional feature for enabling receive bandwidth capping. NICs that advertise receive cap support should drop any receive packet after a given TC on this SQ has exceeded the rate specified in this array (based on the NIC’s scheduling implementation).

### `CrossTcTransmitBandwidthCap`

A ULONG value that specifies the transmit bandwidth cap for traffic across TCs whose corresponding element in **TcEnabledTable** is **TRUE**, if the `NDIS_QOS_SQ_TRANSMIT_CAP_ENABLED` flag is set.

### `MaxNumSqInputs`

A ULONG value that offers a “hint” to the miniport on the likely number of vPorts that the OS will associate with the SQ. This value cannot be modified after SQ creation.

The miniport may use this hint to manage its resources better. The miniport will provide best-effort service to satisfy the request, but may fail due to insufficient resources at SQ creation time or vPort association time.

The miniport must return an error if this value exceeds the **MaxNumSQInputs** value specified by the miniport in [**NDIS_QOS_OFFLOAD_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_offload_capabilities).

## Remarks

The **NDIS_QOS_SQ_PARAMETERS** structure is returned in the OID query request [OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs), which enumerates SQs created on a NIC switch.

**NDIS_QOS_SQ_PARAMETERS** is also returned in the OID method request [OID_QOS_OFFLOAD_CREATE_SQ](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-create-sq), which creates a new SQ on the miniport adapter.

## See also

[OID_QOS_OFFLOAD_ENUM_SQS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-enum-sqs)

[OID_QOS_OFFLOAD_CREATE_SQ](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-create-sq)

[**NDIS_QOS_OFFLOAD_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_offload_capabilities)

[**NDIS_QOS_SQ_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters_enum_array)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS QoS Traffic Classes](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classes)