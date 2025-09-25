# DXGKCB_LOG_ETW_EVENT callback function

## Description

The **DxgkCbLogEtwEvent** function logs an Event Tracing for Windows (ETW) event.

## Parameters

### `EventGuid` [in]

A GUID that identifies the event to be logged.

### `Type` [in]

A constant that specifies the event type. These constants are defined in *Evntrace.h* and have the form of **EVENT_TRACE_TYPE_XX**. **Type** is ignored when **EventGuid** is GUID_DXGKDDI_AZURE_TRIAGE_EVENT.

### `EventBufferSize` [in]

The size, in bytes, of the buffer pointed to by **EventBuffer**. There is a significant performance penalty if the buffer is larger than 256 bytes.

### `EventBuffer` [in]

A pointer to a buffer that contains the information to be logged. This parameter can be NULL, or a pointer to the following structure type depending on the value of **EventGuid**.

## Remarks

If event logging is not enabled, **DxgkCbLogEtwEvent** returns immediately without logging the event.

To enable or disable event logging, call the [**DxgkDdiControlEtwLogging**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_control_etw_logging) function.

If **EventBufferSize** is less than or equal to 256, **DxgkCbLogEtwEvent** can be called an any IRQL. If **EventBufferSize** is greater than 256, **DxgkCbLogEtwEvent** must be called at IRQL = PASSIVE_LEVEL.

### Example: Logging an event with the event logger

The following code example shows how to log an event with the event logger.

```cpp
// {A7BF27A0-7401-4733-9FED-FDB51067FECC}
DEFINE_GUID(R200_DUMMY_LOGGING,
0xa7bf27a0, 0x7401, 0x4733, 0x9f, 0xed, 0xfd, 0xb5, 0x10, 0x67, 0xfe, 0xcc);

VOID
DummyTrace(
    HW_DEVICE_EXTENSION* Adapter
    )
{
    Adapter->ddiCallback.DxgkCbLogEtwEvent(&R200_DUMMY_LOGGING,
  EVENT_TRACE_TYPE_INFO,
  0,
  NULL);
}
```

### Logging Azure driver events

Starting in Windows Server 2022 (WDDM 2.9), a graphics driver's **DxgkCbLogEtwEvent** callback function can expose important events relevant to Azure triage and monitoring. As Azure adds vGPU offerings, it will become more important to have a mechanism to expose important events that the driver sees. Particularly important for monitoring and health is the exposure of function-level resets (VF TDRs) and whole-GPU resets (adapter-wide TDRs). In the future, this framework will allow the OS to expose additional important events that may involve driver-specific behaviors that have triage value when issues arrive.

A driver should use the following GUID to report specific Azure driver events:

``` cpp

DEFINE_GUID(GUID_DXGKDDI_AZURE_TRIAGE_EVENT,
0x45125F6F, 0x6132, 0x4082, 0xAD, 0x17, 0xED, 0x27, 0xF8, 0xDD, 0x02, 0xF9);
```

These events are used by the graphics kernel components to feed triage information into standard Azure monitoring pipelines used for incident triage. They integrate with other graphics events also being exposed to build machine event histories and expose useful queries to be used in the monitoring of the health of the host and the VMs it supports.

When this GUID is used, **EventBuffer** points to a [**DXGKARG_PARTITIONING_EVENT_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkddicb_partitioning_event_notification) structure.

## See also

[**DXGKARG_PARTITIONING_EVENT_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkddicb_partitioning_event_notification)

[**DxgkDdiControlEtwLogging**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_control_etw_logging)