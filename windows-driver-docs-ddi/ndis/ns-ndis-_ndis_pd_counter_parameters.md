# _NDIS_PD_COUNTER_PARAMETERS structure

## Description

This structure holds parameters for the provider counter.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_COUNTER_PARAMETERS** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_COUNTER_PARAMETERS_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_COUNTER_PARAMETERS_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `CounterName`

This member is ignored by the PD provider. It is used by the PD platform for publishing the counter to the Windows Performance Counter subsystem (so that the counter can be viewed using PerfMon and accessed by system APIs programmatically).

### `Type`

An [NDIS_PD_COUNTER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-ndis_pd_counter_type) enumeration value that specifies the counter type.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PD_COUNTER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-ndis_pd_counter_type)

[NdisPDAllocateCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_counter)