# PVIDEO_HW_QUERY_INTERFACE callback function

## Description

*HwVidQueryInterface* returns a miniport driver-implemented functional interface that a child device can call.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `QueryInterface`

Pointer to a [QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface) structure in which the miniport driver should return information about the interface it supports.

## Return value

*HwVidQueryInterface* should return NO_ERROR upon success; otherwise it should return the appropriate error code. For example, a miniport driver should return ERROR_OUTOFMEMORY if it cannot allocate memory to complete the operation.

## Remarks

*HwVidQueryInterface* exposes a communication mechanism between the video miniport driver and the driver of a child device. A miniport driver that exposes such a mechanism should implement this function.

The video port calls *HwVidQueryInterface* when it receives an IRP_MN_QUERY_INTERFACE request. If the miniport driver fails the call, the video port driver passes the request to the parent of the miniport driver's device.

*HwVidQueryInterface* should fill in the members of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure to which *QueryInterface*->**Interface** points as follows:

* Set **Size** to the number of bytes in the INTERFACE structure. This value must not exceed the number of bytes specified by *QueryInterface*->**Size**.
* Set **Version** to the version of the interface being returned by the miniport driver. The miniport driver should best match the version requested by the child driver in *QueryInterface*->**Version**.
* Set **Context** to point to a miniport driver-defined context for the interface. Typically, a miniport driver would set **Context** to point to the device extension identified by *HwDeviceExtension*.
* Initialize **InterfaceReference** and **InterfaceDereference** to point to the miniport driver-implemented reference and dereference routines for this interface.
* Initialize all additional interface-specific members to point to the appropriate routines of the interface being exposed.

A miniport driver that returns an interface is responsible for referencing the interface by calling *QueryInterface*->**Interface.InterfaceReference**. The child driver requesting the interface is responsible for dereferencing it when the driver no longer requires the interface by calling *QueryInterface*->**Interface.InterfaceDereference**. If the child driver passes the interface to another component, the child is responsible for taking out another reference, and the other component is responsible for removing the additional reference when it no longer needs access to the interface. Referencing allows a parent to determine when the interface is still required by the child device, and consequently when the parent can free any interface-associated resources.

The driver of a child device can call into the miniport driver through the functions exposed by *HwVidQueryInterface* at any time without the video port driver's knowledge. Consequently, the miniport driver must synchronize access to itself by acquiring and releasing the video port driver-maintained device lock in all of the functions exposed by *HwVidQueryInterface*.

A child device is enumerated by [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor).

*HwVidQueryInterface* should be made pageable.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface)

[VideoPortAcquireDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportacquiredevicelock)

[VideoPortReleaseDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasedevicelock)