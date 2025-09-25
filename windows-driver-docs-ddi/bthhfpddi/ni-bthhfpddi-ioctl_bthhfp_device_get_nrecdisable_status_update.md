# IOCTL_BTHHFP_DEVICE_GET_NRECDISABLE_STATUS_UPDATE IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_NRECDISABLE_STATUS_UPDATE**
IOCTL Gets noise reduction / echo cancellation (NREC) Disable status updates from the remote Bluetooth device.

This IOCTL is available in Windows 8.1 and later operating systems.

## Parameters

### Major code

### Input buffer

A BOOL that is set to TRUE to request an immediate update. Otherwise, set this to FALSE.

### Input buffer length

The size of a BOOL.

### Output buffer

A BOOL that indicates the new NREC Disable status. See **Remarks** for additional information.

### Output buffer length

The size of a BOOL.

### Input/output buffer

### Input/output buffer length

### Status block

If a request is already pending, then the new request fails with an error code of STATUS_INVALID_DEVICE_REQUEST.

## Remarks

When the NREC Disable status is TRUE, it shows that the remote Bluetooth device has disabled any system-based NREC processing, implying that the remote device has enabled its own NREC signal processing. In this scenario, the audio driver should disable any of its own NREC processing, regardless of whether the processing is being done within the driver code itself, in its digital signal processing (DSP) module, or its audio processing object (APO).

Additionally, in this scenario where NREC is enabled in the remote Bluetooth device, the driver’s APO should return "NREC" in its list of effects, to let applications know that NREC processing is enabled.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)