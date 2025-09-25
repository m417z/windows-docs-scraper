# PVIDEO_HW_FIND_ADAPTER callback function

## Description

*HwVidFindAdapter* performs initialization of data specific to the miniport driver and devices supported by the miniport driver.

## Parameters

### `HwDeviceExtension`

Pointer to the driver's per-device storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `HwContext`

Is **NULL** and should be ignored by the miniport driver.

### `ArgumentString`

Pointer to a null-terminated ASCII string that originates with the user. This pointer can be **NULL**.

### `ConfigInfo`

Pointer to a [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure. The video port driver allocates memory for and initializes this structure with any known configuration information, such as the system IO bus number and values that the miniport driver set in the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure.

### `Again`

Should be ignored by the miniport driver.

## Return value

*HwVidFindAdapter* must return one of the following status codes:

|Return code|Description|
|--- |--- |
|ERROR_DEV_NOT_EXIST|Indicates, for a reenumerable bus, that the miniport driver could not find the device.|
|ERROR_INVALID_PARAMETER|Indicates the miniport driver could not configure or initialize the adapter successfully.|
|NO_ERROR|Indicates success.|

## Remarks

Every video miniport driver must have an *HwVidFindAdapter* function.

The video port driver does the following before it calls *HwVidFindAdapter*:

* Allocates storage for the miniport driver's per-adapter storage area according to the value of **HwDeviceExtensionSize** that the miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function specified in the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure, and zero-initializes the allocated storage.
* Allocates storage for a [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure and fills in all available information based on miniport driver-supplied information in VIDEO_HW_INITIALIZATION_DATA.

The video port driver then calls the miniport driver's *HwVidFindAdapter* function with pointers to the initialized per-adapter storage area and configuration information in the *HwDeviceExtension* and *ConfigInfo* parameters, respectively.

The *HwVidFindAdapter* function for devices on an enumerable bus must do the following:

* Check the size of the VIDEO_PORT_CONFIG_INFO structure to which *ConfigInfo* points to ensure proper versioning.
* Call **VideoPortGetAccessRanges** to obtain the bus-relative physical addresses to which the device will respond. These addresses are assigned by the PnP manager. The miniport driver should pass **NULL** in the *VendorId*, *DeviceId*, and *Slot* parameters of **VideoPortGetAccessRanges**.
* For miniport drivers that support several device types, determine the type of device that the PnP manager has detected. The miniport driver can call **VideoPortGetBusData** to obtain PCI configuration information.
* Fill in any relevant but missing configuration information in the appropriate members of the VIDEO_PORT_CONFIG_INFO structure with adapter-specific data.

*HwVidFindAdapter* should not attempt to initialize the device.

*HwVidFindAdapter* can allocate resources, such as memory and locks, for use by the miniport driver. Those resources can be device-specific or they can be shared by several devices that the miniport driver supports. If *HwVidFindAdapter* returns any value other than NO_ERROR, it must free all device-specific resources before returning. For resources that are shared among several devices, *HwVidFindAdapter* should keep a reference count. For example, the reference count could indicate the number of previous calls to *HwVidFindAdapter* that succeeded. That way, if *HwVidFindAdapter* must fail, and it determines that all previous calls to *HwVidFindAdapter* have failed, it could free the shared resources.

If *HwVidFindAdapter* fails every time it is called by the video port driver, the operating system might unload the miniport driver later. In such a case, any resources that *HwVidFindAdapter* allocated but did not free will leak.

For a device on a reenumerable bus such as ISA, PnP still attempts to start the device, although it is the responsibility of *HwVidFindAdapter* to determine whether the device is actually present. If the device is not found, *HwVidFindAdapter* should return ERROR_DEV_NOT_EXIST.

*HwVidFindAdapter* should also call **VideoPortSetRegistryParameters** to store adapter-specific information in the **HardwareInformation** key. This information is used by the Display program in Control Panel. See [Setting Hardware Information in the Registry](https://learn.microsoft.com/windows-hardware/drivers/display/setting-hardware-information-in-the-registry) for details.

Depending on the adapter and the **AdapterInterfaceType** value in [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info), *HwVidFindAdapter* can call some of the following **VideoPort***Xxx* functions to get the necessary bus-relative configuration data and mapped access ranges to communicate with the adapter:

* [VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata) to get bus-type-specific configuration information about an adapter on a particular I/O bus.
* [VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata) to get VIDEO_DEVICE_DATA_TYPE-specific information from the registry and call [HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine) to process this information.
* [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters) to get configuration information from the registry.
* [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) to get bus-relative access ranges addresses and possibly other hardware configuration values, and to claim them in the registry for use by the driver of an adapter.
* [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) to determine whether bus-relative video memory and/or I/O ports for the adapter can be claimed by the miniport driver; otherwise, a previously loaded driver has already claimed the resource in the registry and *HwVidFindAdapter* must try to claim other access ranges if possible or fail.
* [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) to map each successfully claimed bus-relative base address and range size, as described in a [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) structure, to [system space](https://learn.microsoft.com/windows-hardware/drivers/) logical addresses. *HwVidFindAdapter* must successfully call **VideoPortVerifyAccessRanges** or **VideoPortGetAccessRanges** before it can call **VideoPortGetDeviceBase**.

If the driver does not handle interrupts, *HwVidFindAdapter* should set both **BusInterruptLevel** and **BusInterruptVector** in the VIDEO_PORT_CONFIG_INFO structure to zero after its call to **VideoPortGetAccessRanges**. If both members are zero, the video port driver does not connect the interrupt for the miniport driver. Explicitly setting both **BusInterruptLevel** and **BusInterruptVector** to zero in *HwVidFindAdapter* disables the [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) entry point, if any, that was set up by the miniport driver's **DriverEntry** routine.

*HwVidFindAdapter* must not leave an unsupported adapter with its state changed. For VGA/SVGA adapters, *HwVidFindAdapter* must leave the adapter in a VGA state and restore any extended registers it might have modified to their original condition.

*HwVidFindAdapter* should be made pageable.

## See also

[DriverEntry of Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-video-miniport-driver)

[DrvAssertMode](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvassertmode)

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportfreedevicebase)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)