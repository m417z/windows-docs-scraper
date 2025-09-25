# PCAM_STOP_CAPTURE_ROUTINE_EX callback function

## Description

A camera minidriver's **CamStopCaptureEx** callback function performs any processing after the stream is stopped.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `StreamNumber`

Indicates the stream number.

## Return value

**CamStopCaptureEx** returns STATUS_SUCCESS or an appropriate error code. This return value is the completion code for the read IRP.

## Remarks

USBCAMD calls the minidriver's **CamStopCaptureEx** callback function immediately after the isochronous video stream is stopped. Typically, a camera minidriver selects an alternate setting within the USB video streaming interface that uses no additional bandwidth.

The original USBCAMD does not call **CamStopCaptureEx**.

This function is required.