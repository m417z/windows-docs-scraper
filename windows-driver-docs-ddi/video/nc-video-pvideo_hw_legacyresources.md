# PVIDEO_HW_LEGACYRESOURCES callback function

## Description

*HwVidLegacyResources* returns a list of resources that are not listed in a device's PCI configuration space but that are decoded by the device.

## Parameters

### `VendorId` [in]

Specifies a code that identifies the device's vendor. This is the vendor ID specified in the device's PCI configuration space. For more information, see [Identifiers for PCI Devices](https://learn.microsoft.com/windows-hardware/drivers/install/identifiers-for-pci-devices).

### `DeviceId` [in]

Specifies a code that identifies the particular device. This is the device ID specified in the device's PCI configuration space.

### `LegacyResourceList` [in, out]

Pointer to an array of [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) structures. Each structure describes a device I/O port or memory range for the graphics adapter that is not listed in PCI configuration space.

### `LegacyResourceCount` [in, out]

Is the number of elements in the array to which *LegacyResourceList* points.

## Remarks

Legacy resources are those resources that are not listed in the device's PCI configuration space but that are decoded by the device. If the legacy resource list for the device is not known at compile time, a miniport driver should implement a *HwVidLegacyResources*  function and initialize the **HwGetLegacyResources** member of [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) to point to this function. For example, a miniport driver that supports two devices with different sets of legacy resources would implement *HwVidLegacyResources*  to report the legacy resources for a particular device at run time.

The resources returned by *HwVidLegacyResources*  are added to the list of resources that PnP reserves for the device.

*HwVidLegacyResources* should be made pageable.

## See also

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)