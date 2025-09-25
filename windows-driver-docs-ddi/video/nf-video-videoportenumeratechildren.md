# VideoPortEnumerateChildren function

## Description

The **VideoPortEnumerateChildren** function allows a video miniport driver to force a reenumeration of its child devices.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Reserved` [in]

Must be set to **NULL**.

## Return value

**VideoPortEnumerateChildren** returns NO_ERROR.

## Remarks

Some devices generate an interrupt when new hardware is connected to the system, or when existing hardware is disconnected from the system. For these devices, **VideoPortEnumerateChildren** can make such system changes as seamless as possible. The following is one possible scenario that forces the reenumeration of child devices through **VideoPortEnumerateChildren**:

* New hardware is connected, which generates an interrupt.
* The miniport driver's interrupt handler ([HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)) queues a DPC routine ([HwVidDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_dpc_routine)) by calling [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc).
* The asynchronously executed DPC contains a call to **VideoPortEnumerateChildren**.

**VideoPortEnumerateChildren** causes [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) to be called, allowing the Plug and Play Manager to enumerate all of the adapter's child devices.

## See also

[HwVidDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_dpc_routine)

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc)