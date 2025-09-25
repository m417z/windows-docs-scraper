# _VIDEO_HW_INITIALIZATION_DATA structure

## Description

The VIDEO_HW_INITIALIZATION_DATA structure specifies the entry points and storage requirements for the miniport driver. This structure is created on the stack and initialized by the miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

## Members

### `HwInitDataSize`

Is the size in bytes of this structure. In effect, this indicates the version of VIDEO_HW_INITIALIZATION_DATA being used.

### `AdapterInterfaceType`

Is currently ignored by the video port and should remain zero-initialized.

### `HwFindAdapter`

Pointer to the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function, which is required for all miniport drivers.

### `HwInitialize`

Pointer to the miniport driver's [HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize) function, which is required for all miniport drivers.

### `HwInterrupt`

Pointer to the miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function, which is required only if the miniport driver's adapter generates interrupts. Otherwise, this pointer must be **NULL**.

### `HwStartIO`

Pointer to the miniport driver's [HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io) function, which is required for all miniport drivers.

### `HwDeviceExtensionSize`

Specifies the size in bytes of the storage the miniport driver requires for its private, adapter-specific device extension. A miniport driver uses this storage to hold driver-determined per-adapter information, such as the mapped logical address ranges for the adapter registers and whatever context information the driver maintains about its I/O operations.

A pointer to the device extension is passed in every call made to the miniport driver's standard functions except [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver), [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine), and any *SvgaHwIoPortXxx* functions. The video port driver allocates the memory for the device extension and initializes it with zeros before it is passed to the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function.

### `StartingDeviceNumber`

Must be set to zero.

### `HwResetHw`

Pointer to the miniport driver's [HwVidResetHw](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_reset_hw) function, which is required for any miniport driver of an adapter that does not reset fully on a soft reboot of the machine. Drivers of SVGA adapters that are fully reset to a VGA standard character mode on receipt of an INT10, MODE3-type command usually set this to **NULL**.

### `HwTimer`

Pointer to a miniport driver's [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) function, which is optional. This pointer can be **NULL**.

### `HwStartDma`

Reserved for system use.

### `HwSetPowerState`

Pointer to the miniport driver's [HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set) function, which is required for all miniport drivers.

### `HwGetPowerState`

Pointer to the miniport driver's [HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get) function, which is required for all miniport drivers.

### `HwGetVideoChildDescriptor`

Pointer to the miniport driver's [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function, which is required for all miniport drivers.

### `HwQueryInterface`

Pointer to the miniport driver's [HwVidQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface) function. This can be optionally implemented in a miniport driver that supports external programming interfaces for inter-device communication, such as [I2C](https://learn.microsoft.com/windows-hardware/drivers/) (or I²C) support for MPEG decoders. Otherwise, this member should be set to **NULL**.

### `HwChildDeviceExtensionSize`

Is the size in bytes of the device extension associated with the display output device. The miniport driver should fill in this member only if the miniport driver needs to manage the monitor configuration data separately from the adapter board configuration.

### `HwLegacyResourceList`

Pointer to an array of [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) structures. Each structure describes a device I/O port or memory range for the video adapter that is not listed in PCI configuration space.

### `HwLegacyResourceCount`

Is the number of elements in the array to which **HwLegacyResourceList** points.

### `HwGetLegacyResources`

Pointer to the miniport driver's [HwVidLegacyResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_legacyresources) function, which enables the driver to specify its legacy resources based on its device and vendor IDs.

### `AllowEarlyEnumeration`

Allows the miniport driver to enumerate its child devices before the adapter is started; that is, the video port driver can call [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) before [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) when this member is set to **TRUE**.

### `Reserved`

Reserved for system use.

## Remarks

A miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function must initialize this structure with zeros before it sets relevant values in any member.

The video port driver will ignore the **HwLegacyResourceCount** and **HwLegacyResourceList** members when **HwGetLegacyResources** is initialized with a pointer to a [HwVidLegacyResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_legacyresources) implementation.

## See also

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[HwVidLegacyResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_legacyresources)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)