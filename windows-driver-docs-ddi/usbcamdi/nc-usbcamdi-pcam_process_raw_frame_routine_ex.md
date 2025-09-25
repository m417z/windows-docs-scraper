# PCAM_PROCESS_RAW_FRAME_ROUTINE_EX callback function

## Description

A camera minidriver's **CamProcessRawVideoFrameEx** callback function decodes a raw video frame.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `FrameContext`

Pointer to the minidriver's frame context.

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

### `ActualRawFrameLength`

Contains the length of the actual buffer received from the camera. This value is specified in bytes.

### `StreamNumber`

Indicates the stream number with which this frame is associated with.

## Return value

**CamProcessRawVideoFrameEx** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Before USBCAMD calls the minidriver's **CamProcessRawVideoFrameEx** callback, it sets the first DWORD in the buffer pointed to by the *FrameBuffer* parameter to the value *0xdeadbeef.* After calling the minidriver's **CamProcessRawVideoFrameEx** callback USBCAMD checks the first DWORD in the buffer pointed to by the *FrameBuffer* parameter for the value *0xdeadbeef* to determine if **CamProcessRawVideoFrameEx** successfully copied the video frame from the buffer pointed to by the *RawFrameBuffer* parameter into the buffer pointed to by the *FrameBuffer* parameter.

This function is not called if either one of the following bits are set in the *CamControlFlag* argument passed to the [USBCAMD_InitializeNewInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_initializenewinterface) function:

USBCAMD_CamControlFlag_NoVideoRawProcessing

USBCAMD_CamControlFlag_NoStillRawProcessing

USBCAMD clears the stream header options flag before passing the raw frame to the minidriver. The default flag is key frames only. The camera minidriver should set the stream header option flags appropriately if it needs to indicate anything other than key frames.

The original USBCAMD does not call **CamProcessRawVideoFrameEx**.

This function is optional.