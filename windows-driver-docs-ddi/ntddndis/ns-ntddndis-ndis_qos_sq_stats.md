## Description

The **NDIS_QOS_SQ_STATS** structure is used by [OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats) to query the stats of an NDIS Quality of Service (QoS) Scheduler Queue (SQ).

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_SQ_STATS** structure. This member is formatted as an [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT, the **Revision** member to NDIS_QOS_SQ_STATS_REVISION_1, and the **Size** member to NDIS_SIZEOF_QOS_SQ_STATS_REVISION_1.

### `Flags`

Not used in NDIS_QOS_SQ_STATS_REVISION_1. The caller sets this field to **zero**.

### `SqId`

An NDIS_QOS_SQ_ID containing the SQ ID of the SQ. NDIS assigns this ID.

### `SqType`

An [**NDIS_QOS_SQ_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-ndis_qos_sq_type) that contains the type of this SQ. This can be **NdisQSQosSqSQTypeStandard** from the enum definition of **NDIS_QOS_SQ_TYPE**.

### `BytesTransmitted`

An array of UINT64 elements, one for each traffic class (TC). Each element specifies the total number of bytes on that TC for this SQ that have been successfully transmitted.

### `PktsTransmitted`

An array of UINT64 elements, one for each traffic class. Each element specifies the total number of packets on that TC for this SQ that have been successfully transmitted.

## Remarks

If the query [OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats) OID contains a valid vPortID, then the returned stats are specific to the vPort specified on this SQ.

If the query OID does not contain a valid vPortID, then the returned stats specify the total stats across all vPorts associated with the SQ.

## See also

[OID_QOS_OFFLOAD_SQ_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-offload-sq-stats)

[**NDIS_QOS_SQ_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-ndis_qos_sq_type)

[**NDIS_QOS_SQ_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-ndis_qos_sq_parameters_enum_array)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)