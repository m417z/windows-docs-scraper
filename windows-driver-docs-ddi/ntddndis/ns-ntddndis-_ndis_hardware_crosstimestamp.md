# _NDIS_HARDWARE_CROSSTIMESTAMP structure

## Description

The **NDIS_HARDWARE_CROSSTIMESTAMP** structure describes the cross timestamp between a NIC’s hardware clock and a system clock.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_HARDWARE_CROSSTIMESTAMP** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.

* Set the **Revision** member to **NDIS_HARDWARE_CROSSTIMESTAMP_REVISION_1**.

* Set the **Size** member to **NDIS_SIZEOF_HARDWARE_CROSSTIMESTAMP_REVISION_1**.

### `Flags`

Reserved for future use. The miniport driver must not change this value.

### `SystemTimestamp1`

The performance counter value (QPC) obtained by calling [**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter).

### `HardwareClockTimestamp`

The NIC hardware clock’s current value. This should be the raw hardware clock value of the NIC.

### `SystemTimestamp2`

Another performance counter value (QPC) obtained by calling **KeQueryPerformanceCounter**.

## Remarks

When a miniport driver receives the OID request of [**OID_TIMESTAMP_GET_CROSSTIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/network/oid-timestamp-get-crosstimestamp), the driver completes the OID by filling the **InformationBuffer** in the **QUERY_INFORMATION** with an **NDIS_HARDWARE_CROSSTIMESTAMP** structure.

The driver should fill the **SystemTimestamp1**, **HardwareClockTimestamp** and **SystemTimestamp2** fields with timestamps taken as close to each other as possible and in the following order:

1. **SystemTimestamp1**

2. **HardwareClockTimestamp**

3. **SystemTimestamp2**

The miniport driver and hardware are free to optimize the collection of these timestamps depending on any advanced hardware capabilities. However, the **SystemTimestamp1** and **SystemTimestamp2** values returned on OID completion must accurately correspond to the performance counter (QPC) value at the time of capture. The **HardwareClockTimestamp** must correspond to the NIC’s hardware clock value at the point of capture. If a particular implementation can more accurately determine two timestamps rather than three (for example, one system timestamp and the corresponding NIC hardware clock timestamp), then it should set the **SystemTimestamp2** field to the same value as **SystemTimestamp1**.

The miniport driver should not set the **SystemTimestamp1**, **HardwareClockTimestamp**, or **SystemTimestamp2** values to **zero**.

## See also

[**OID_TIMESTAMP_GET_CROSSTIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/network/oid-timestamp-get-crosstimestamp)

[**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)