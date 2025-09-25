## Description

**DXGKDDICB_PARTITIONING_EVENT_NOTIFICATION** is the structure used by the [**DxgkCbLogEtwEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_log_etw_event) callback to log an event when its **EventGuid** parameter is GUID_DXGKDDI_AZURE_TRIAGE_EVENT.

## Members

### `hAdapter`

The adapter handle used by the driver to identify the instance reporting the event.

### `EventType`

a [**DXGIDDI_PARTITIONING_EVENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgiddi_partitioning_event_type) value that identifies the type of event being reported.

### `PartitionId`

The notification structure is the same as used elsewhere in the GPU Partitioning DDI (for example, [**DXGKDDI_CREATEVIRTUALGPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_createvirtualgpu)) and is a number in 0 to (Partitions - 1) when the event refers to something occurring to a virtual function. If the event refers to something occurring in the context of the physical function, it should report ULONG_MAX - 1. To identify events that occur across the entire GPU, it should report ULONG_MAX.

### `EventDescription`

A useful, descriptive string for the driver to identify the meaning of the event. The driver can also use the **EventData*N*** members as additional string information if this is useful.

### `EventData1`

An optional first parameter that contains additional useful data that may help triage the event.

### `EventData2`

An optional second parameter that contains additional useful data that may help triage the event.

### `EventData3`

An optional third parameter that contains additional useful data that may help triage the event.

### `EventData4`

An optional fourth parameter that contains additional useful data that may help triage the event.

### `EventData5`

An optional fifth parameter that contains additional useful data that may help triage the event.

## Remarks

See [**DxgkCbLogEtwEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_log_etw_event) for additional details.

## See also

[**DxgkCbLogEtwEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_log_etw_event)

[**DXGIDDI_PARTITIONING_EVENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgiddi_partitioning_event_type)