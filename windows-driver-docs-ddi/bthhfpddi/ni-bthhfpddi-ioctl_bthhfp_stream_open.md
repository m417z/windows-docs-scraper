# IOCTL_BTHHFP_STREAM_OPEN IOCTL

## Description

The **IOCTL_BTHHFP_STREAM_OPEN**
IOCTL requests an open synchronous connection-oriented (SCO) channel to transmit audio data over the air.

## Parameters

### Major code

### Input buffer

N/A

### Input buffer length

N/A

### Output buffer

N/A

### Output buffer length

N/A

### Input/output buffer

### Input/output buffer length

### Status block

A STATUS_DEVICE_BUSY message to indicate that the stream channel is already open.

## Remarks

This request can remain pending for several seconds while resources are established.

While the stream channel is open the target driver attempts to keep the SCO channel open for audio data transfer. However the SCO channel might close briefly, if the remote device disconnects the SCO channel. The target driver will attempt to reopen the SCO channel in this case, without requiring any action from the client audio driver.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)