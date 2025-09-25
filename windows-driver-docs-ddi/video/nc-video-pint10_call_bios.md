# PINT10_CALL_BIOS callback function

## Description

The *Int10CallBios* function allows a miniport driver to call the kernel to perform an INT 10h operation, causing the BIOS ROM code on the device to execute natively.

## Parameters

### `Context`

Pointer to a video port driver-defined context for the interface. This should be the same as the value in the **Context** member of the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure after [VideoPortQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryservices) returns.

### `BiosArguments`

Pointer to a video miniport driver-initialized [INT10_BIOS_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_int10_bios_arguments) structure containing the values of the x86 registers. Any registers that are not needed in the INT10 BIOS call should be set to 0. When the function returns, some members of the INT10_BIOS_ARGUMENTS structures can have different values than before the call.

## Return value

The **Int10CallBios** function returns NO_ERROR upon success. Otherwise it returns an appropriate error code.

## Remarks

The video port implements this function, which can be accessed through a pointer in the [VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface) structure.

## See also

[VIDEO_PORT_INT10_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_int10_interface)