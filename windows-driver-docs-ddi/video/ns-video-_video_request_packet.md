# _VIDEO_REQUEST_PACKET structure

## Description

A pointer to a VIDEO_REQUEST_PACKET structure is passed to the miniport driver's [HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io) function by the video port driver. The video port driver sets up the [VRP](https://learn.microsoft.com/windows-hardware/drivers/) from the IRP code (see [IRP Major Function Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-major-function-codes)) sent in response to a GDI call to [EngDeviceIoControl](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engdeviceiocontrol). Usually, the corresponding display driver makes the call to **EngDeviceIoControl** when it needs support from the video port-miniport driver pair. The video port driver calls the miniport driver with the *VRP* to process the given IOCTL_VIDEO_*XXX* request.

## Members

### `IoControlCode`

Specifies an IOCTL_VIDEO_*XXX* value passed to the **EngDeviceIoControl** function by the caller and sent to the video port driver in an IRP code. For more information about the set of system-defined IOCTL_VIDEO_*XXX* that miniport drivers must support, see [Video Miniport Driver I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `StatusBlock`

Pointer to a STATUS_BLOCK structure in the [VRP](https://learn.microsoft.com/windows-hardware/drivers/). **StatusBlock** is filled in by the miniport driver with return information upon completion of each VRP.

### `InputBuffer`

Pointer to an input buffer that contains information passed in by the caller. The structure for the data depends on the value of **IoControlCode**. This member actually points to the same buffer as that indicated by **OutputBuffer**.

### `InputBufferLength`

Specifies the size in bytes of the input buffer.

### `OutputBuffer`

Pointer to an output buffer into which the miniport driver transfers data to be returned to the caller. The structure for the data depends on the value of **IoControlCode.** Because this member points to the same buffer as **InputBuffer**, a miniport driver must not write output in the **OutputBuffer** before it has consumed all input data from the **InputBuffer**.

### `OutputBufferLength`

Specifies the size in bytes of the output buffer. A miniport driver cannot enlarge this buffer. A miniport driver should set the **Status** member of the **StatusBlock** with ERROR_INSUFFICIENT_BUFFER or ERROR_MORE_DATA if the given **OutputBuffer** is too small to contain all the returned information.

## See also

[HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io)

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[Video Miniport Driver I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/)