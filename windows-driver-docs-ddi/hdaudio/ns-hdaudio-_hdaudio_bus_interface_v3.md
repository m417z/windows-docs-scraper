# _HDAUDIO_BUS_INTERFACE_V3 structure

## Description

## Members

### `Size`

Specifies the size, in bytes, of the HDAUDIO_BUS_INTERFACE_V3 structure.

### `Version`

Specifies the version of the baseline HD Audio DDI.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to a driver-supplied routine that increments the reference count for the interface.

### `InterfaceDereference`

A pointer to a driver-supplied routine that decrements the reference count for the interface.

### `TransferCodecVerbs`

A function pointer to the TransferCodecVerbs routine.

### `AllocateCaptureDmaEngine`

A function pointer to the AllocateCaptureDmaEngine routine.

### `AllocateRenderDmaEngine`

A function pointer to the AllocateRenderDmaEngine routine.

### `ChangeBandwidthAllocation`

A function pointer to the ChangeBandwidthAllocation routine.

### `AllocateDmaBuffer`

A function pointer to the AllocateDmaBuffer routine.

### `FreeDmaBuffer`

A function pointer to the FreeDmaBuffer routine.

### `FreeDmaEngine`

A function pointer to the FreeDmaEngine routine.

### `SetDmaEngineState`

A function pointer to the SetDmaEngineState routine.

### `GetWallClockRegister`

A function pointer to the GetWallClockRegister routine.

### `GetLinkPositionRegister`

A function pointer to the GetLinkPositionRegister routine.

### `RegisterEventCallback`

A function pointer to the RegisterEventCallback routine.

### `UnregisterEventCallback`

A function pointer to the UnregisterEventCallback routine.

### `GetDeviceInformation`

A function pointer to the GetDeviceInformation routine.

### `GetResourceInformation`

A function pointer to the GetResourceInformation routine.

### `AllocateDmaBufferWithNotification`

A function pointer to the AllocateDmaBufferWithNotification routine.

### `FreeDmaBufferWithNotification`

A function pointer to the FreeDmaBufferWithNotification routine.

### `RegisterNotificationEvent`

A function pointer to the RegisterNotificationEvent routine.

### `UnregisterNotificationEvent`

A function pointer to the UnregisterNotificationEvent routine.

### `RegisterNotificationCallback`

A function pointer to the RegisterNotificationCallback routine.

### `UnregisterNotificationCallback`

A function pointer to the UnregisterNotificationCallback routine.

## Remarks

The [IRP_MN_QUERY_INTERFACE IOCTL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) uses this structure to provide interface information to a client that is querying the HD Audio bus driver for the HD Audio DDI.

The names and definitions of the first five members of the HDAUDIO_BUS_INTERFACE_V3 structure (Size, Version, Context, InterfaceReference, and InterfaceDereference) are the same as in the INTERFACE structure. The remaining members are specific to the baseline HD Audio DDI and specify function pointers to the routines in the DDI.

## See also

[IRP_MN_QUERY_INTERFACE IOCTL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)