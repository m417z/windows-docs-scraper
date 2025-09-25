# PCAM_NEW_FRAME_ROUTINE_EX callback function

## Description

A camera minidriver's **CamNewVideoFrameEx** callback function initializes a new video frame context structure.

## Parameters

### `DeviceContext`

Specifies the minidriver device context.

### `FrameContext`

Specifies the frame context to be initialized.

### `StreamNumber`

Indicates the stream associated with this new frame.

### `FrameLength`

Pointer to the raw frame buffer length. The length is expressed in bytes. The camera minidriver may decrease this value if it does not require a buffer transfer on the USB bus of the specified size. The camera minidriver should not increase this value.

## Remarks

USBCAMD calls the camera minidriver's **CamNewVideoFrameEx** callback function at IRQL = DISPATCH_LEVEL.

The original USBCAMD does not call **CamNewVideoFrameEx**.

This function is optional.