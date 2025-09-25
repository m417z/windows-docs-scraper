# _HDAUDIO_BUS_INTERFACE_V2 structure

## Description

The HDAUDIO_BUS_INTERFACE_V2 structure specifies the information that a client requires to call the routines in the HDAUDIO_BUS_INTERFACE_V2 version of the HD Audio DDI. The interface represented by this structure provides all the functionality of [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface) and can also support flexible DMA-driven event notification.

## Members

### `Size`

Specifies the size, in bytes, of the HDAUDIO_BUS_INTERFACE_V2 structure.

### `Version`

Specifies the version of the baseline HD Audio DDI.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to a driver-supplied routine that increments the reference count for the interface.

### `InterfaceDereference`

A pointer to a driver-supplied routine that decrements the reference count for the interface.

### `TransferCodecVerbs`

A function pointer to the [TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine.

### `AllocateCaptureDmaEngine`

A function pointer to the [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) routine.

### `AllocateRenderDmaEngine`

A function pointer to the [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine) routine.

### `ChangeBandwidthAllocation`

A function pointer to the [ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation) routine.

### `AllocateDmaBuffer`

A function pointer to the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) routine.

### `FreeDmaBuffer`

A function pointer to the [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routine.

### `FreeDmaEngine`

A function pointer to the [FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine) routine.

### `SetDmaEngineState`

A function pointer to the [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state) routine.

### `GetWallClockRegister`

A function pointer to the [GetWallClockRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_wall_clock_register) routine.

### `GetLinkPositionRegister`

A function pointer to the [GetLinkPositionRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_link_position_register) routine.

### `RegisterEventCallback`

A function pointer to the [RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback) routine.

### `UnregisterEventCallback`

A function pointer to the [UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback) routine.

### `GetDeviceInformation`

A function pointer to the [GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information) routine.

### `GetResourceInformation`

A function pointer to the [GetResourceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_resource_information) routine.

### `AllocateDmaBufferWithNotification`

A function pointer to the [AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification) routine.

### `FreeDmaBufferWithNotification`

A function pointer to the [FreeDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer_with_notification) routine.

### `RegisterNotificationEvent`

A function pointer to the [RegisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_event) routine.

### `UnregisterNotificationEvent`

A function pointer to the [UnregisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_notification_event) routine.

## Remarks

The [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IOCTL uses this structure to provide interface information to a client that is querying the HD Audio bus driver for the HD Audio DDI.

The names and definitions of the first five members of the **HDAUDIO_BUS_INTERFACE_V2** structure (Size, Version, Context, InterfaceReference, and InterfaceDereference) are the same as in the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. The remaining members are specific to the baseline HD Audio DDI and specify function pointers to the routines in the DDI.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[FreeDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer_with_notification)

[FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine)

[GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information)

[GetLinkPositionRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_link_position_register)

[GetResourceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_resource_information)

[GetWallClockRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_wall_clock_register)

[RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback)

[RegisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_event)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)

[TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs)

[UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback)

[UnregisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_notification_event)