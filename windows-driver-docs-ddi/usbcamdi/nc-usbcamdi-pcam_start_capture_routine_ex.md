# PCAM_START_CAPTURE_ROUTINE_EX callback function

## Description

A camera minidriver's **CamStartCaptureEx** callback function selects the appropriate alternate setting within the USB video streaming interface and prepares the device to stream.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `StreamNumber`

Indicates the stream number.

## Return value

**CamStartCaptureEx** returns STATUS_SUCCESS or an appropriate error code. This return value is the completion code for the read IRP.

## Remarks

The original USBCAMD does not call **CamStartCaptureEx**.

This function is required.