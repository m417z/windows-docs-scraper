# PCAM_INITIALIZE_ROUTINE callback function

## Description

A camera minidriver's callback function initializes the device or performs any minidriver-specific clean-up that is required.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

## Return value

**CamInitialize** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

**About CamInitialize**

USBCAMD calls the camera minidriver's **CamInitialize** callback function the first time the device is used.

**CamInitialize** is called by both the original USBCAMD and USBCAMD2.

This function is required.

**About CamUnInitialize**

USBCAMD calls the camera minidriver's **CamUnInitialize** callback function while processing an [SRB_UNINITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-uninitialize-device) request. The **CamUnInitialize** function in version 1.0 is invoked after the user no longer requires the peripheral for that session.

Whereas the stream class driver automatically resets values associated with the minidriver, this call allows the minidriver to deallocate any specific resources used during its operation, such as memory used to store processed and decoded video frames.

**CamUnInitialize** is called by both versions 1.0 and 2.0 of USBCAMD.

This function is required.