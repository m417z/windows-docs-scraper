# VideoPortInitialize function

## Description

The **VideoPortInitialize** function performs part of the miniport driver initialization, allocating system resources for the miniport driver.

## Parameters

### `Argument1`

A pointer with which the operating system called [DriverEntry of Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-video-miniport-driver).

### `Argument2`

A second pointer with which the operating system called **DriverEntry**.

### `HwInitializationData`

Pointer to the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure on the stack. The miniport driver's **DriverEntry** routine zero-initialized this structure and then filled it in with driver-specific configuration information describing a video adapter that the miniport driver can support.

### `HwContext`

Must be **NULL**.

## Return value

**VideoPortInitialize** returns the final status of the initialization operation.

## Remarks

Every video miniport driver must call **VideoPortInitialize** from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function. **DriverEntry** can call **VideoPortInitialize** only after it has first zero-initialized and then set up the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure. **VideoPortInitialize** can be called only from a miniport driver's **DriverEntry** function.

The **VideoPortInitialize** function:

* Checks the validity of the miniport driver's VIDEO_HW_INITIALIZATION_DATA specifications.
* Allocates memory for and zero-initializes a [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure.
* Fills in as much adapter configuration information as it can in VIDEO_PORT_CONFIG_INFO.
* Fills in some of the public members of the device object created by the system to represent the graphics adapter. The video port driver manages the device objects, therefore, the miniport driver need not be concerned with device object details.
* Allocates memory for, and zero-initializes the device extension of, the device object. A *device extension* is each miniport driver's primary and only global storage area for adapter-specific state information. The miniport driver specifies the size of the device extension in the **HwDeviceExtensionSize** member of VIDEO_HW_INITIALIZATION_DATA. The video port driver passes this device extension to most of the miniport driver functions that it calls.
* Collects and stores pertinent information in the device extension.

The miniport driver's **DriverEntry** routine propagates the value returned by **VideoPortInitialize** back to its caller. Miniport drivers should not use this return value.

## See also

[DriverEntry of Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-video-miniport-driver)

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)