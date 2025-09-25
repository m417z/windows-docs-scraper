# PCAM_PROCESS_RAW_FRAME_ROUTINE callback function

## Description

[CamProcessRawVideoFrame is not supported and may be altered or unavailable in the future. Instead, use [CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex).
]

A camera minidriver's **CamProcessRawVideoFrame** callback function decodes a raw video frame.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `FrameContext`

Pointer to the camera minidriver's frame context.

### `FrameBuffer`

Pointer to the buffer that receives the final processed video frame. See the Remarks section for more information about how USBCAMD uses this parameter.

### `FrameLength`

Specifies the length of the frame buffer (from the original read request) in bytes.

### `RawFrameBuffer`

Pointer to the buffer containing the received USB packets. See the Remarks section for more information about how USBCAMD uses this parameter.

### `RawFrameLength`

Specifies the length of *RawFrameBuffer* in bytes.

### `NumberOfPackets`

Specifies the number of USB packets received into *RawFrameBuffer*.

### `BytesReturned`

Pointer to the number of bytes transferred. The minidriver must set this to zero if it encounters any errors during processing, as described in [Data Flow Using Isochronous Pipes](https://learn.microsoft.com/windows-hardware/drivers/stream/data-flow-using-isochronous-pipes). See the Remarks section for more information about how USBCAMD uses this parameter.

## Return value

**CamProcessRawVideoFrame** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Before USBCAMD calls the minidriver's **CamProcessRawVideoFrame** callback, it sets the first DWORD in the buffer pointed to by the *FrameBuffer* parameter to the value *0xdeadbeef.* After calling the minidriver's **CamProcessRawVideoFrame** callback USBCAMD checks the first DWORD in the buffer pointed to by the *FrameBuffer* parameter for the value *0xdeadbeef* to determine if **CamProcessRawVideoFrame** successfully copied the video frame from the buffer pointed to by the *RawFrameBuffer* parameter into the buffer pointed to by the *FrameBuffer* parameter.

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

This function is optional.

## See also

[CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex)