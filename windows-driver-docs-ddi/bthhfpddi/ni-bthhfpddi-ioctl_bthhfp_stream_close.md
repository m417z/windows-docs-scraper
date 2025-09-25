# IOCTL_BTHHFP_STREAM_CLOSE IOCTL

## Description

The **IOCTL_BTHHFP_STREAM_CLOSE**
IOCTL indicates that the client driver no longer requires the synchronous connection-oriented (SCO) channel for streaming audio.

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

N/A

## Remarks

The request completes immediately.

The audio driver starts this request when the KS pin transitions to the KSSTATE_STOP state, and should not finish the pin state transition until this request completes.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)