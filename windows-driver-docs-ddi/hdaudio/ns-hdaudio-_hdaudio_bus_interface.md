# _HDAUDIO_BUS_INTERFACE structure

## Description

The HDAUDIO_BUS_INTERFACE structure specifies the information that a client requires to call the routines in the HDAUDIO_BUS_INTERFACE version of the HD Audio DDI. Another variant of this DDI is specified by the [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

## Members

### `Size`

Specifies the size in bytes of the HDAUDIO_BUS_INTERFACE structure.

### `Version`

Specifies the version of the baseline HD Audio DDI.

### `Context`

Pointer to interface-specific context information.

### `InterfaceReference`

Pointer to a driver-supplied routine that increments the interface's reference count.

### `InterfaceDereference`

Pointer to a driver-supplied routine that decrements the interface's reference count.

### `TransferCodecVerbs`

Function pointer to the [TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs) routine.

### `AllocateCaptureDmaEngine`

Function pointer to the [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) routine.

### `AllocateRenderDmaEngine`

Function pointer to the [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine) routine.

### `ChangeBandwidthAllocation`

Function pointer to the [ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation) routine.

### `AllocateDmaBuffer`

Function pointer to the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) routine.

### `FreeDmaBuffer`

Function pointer to the [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routine.

### `FreeDmaEngine`

Function pointer to the [FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine) routine.

### `SetDmaEngineState`

Function pointer to the [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state) routine.

### `GetWallClockRegister`

Function pointer to the [GetWallClockRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_wall_clock_register) routine.

### `GetLinkPositionRegister`

Function pointer to the [GetLinkPositionRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_link_position_register) routine.

### `RegisterEventCallback`

Function pointer to the [RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback) routine.

### `UnregisterEventCallback`

Function pointer to the [UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback) routine.

### `GetDeviceInformation`

Function pointer to the [GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information) routine.

### `GetResourceInformation`

Function pointer to the [GetResourceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_resource_information) routine.

## Remarks

The [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IOCTL uses this structure to provide interface information to a client that is querying the HD Audio bus driver for the HD Audio DDI. Another variant of this DDI is specified by the HDAUDIO_BUS_INTERFACE_BDL structure.

The HDAUDIO_BUS_INTERFACE and HDAUDIO_BUS_INTERFACE_BDL structures are similar but have the following differences:

* HDAUDIO_BUS_INTERFACE has two members, **AllocateDmaBuffer** and **FreeDmaBuffer**, that are not present in HDAUDIO_BUS_INTERFACE_BDL.
* HDAUDIO_BUS_INTERFACE_BDL has three members, [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer), [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer), and [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl), that are not present in HDAUDIO_BUS_INTERFACE.

For more information, see [Differences Between the HD Audio DDI Versions](https://learn.microsoft.com/windows-hardware/drivers/audio/differences-between-the-hd-audio-ddi-versions).

The names and definitions of the first five members (**Size**, **Version**, **Context**, **InterfaceReference**, and **InterfaceDereference**) are the same as in the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. The remaining members are specific to the baseline HD Audio DDI and specify function pointers to the routines in the DDI. For more information, see [Obtaining an HDAUDIO_BUS_INTERFACE DDI Object](https://learn.microsoft.com/windows-hardware/drivers/audio/obtaining-an-hdaudio-bus-interface-ddi-object).

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine)

[GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information)

[GetLinkPositionRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_link_position_register)

[GetResourceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_resource_information)

[GetWallClockRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_wall_clock_register)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)

[TransferCodecVerbs](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-ptransfer_codec_verbs)

[UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback)