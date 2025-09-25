# IOCTL_BTHHFP_DEVICE_GET_CONNECTION_STATUS_UPDATE IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_CONNECTION_STATUS_UPDATE**
IOCTL Gets a connection status update.

## Parameters

### Major code

### Input buffer

A BOOL that is set to TRUE to request an immediate update. Otherwise, set this to FALSE.

### Input buffer length

The size of a BOOL.

### Output buffer

A BOOL that is the new connection status. TRUE if connected. FALSE if not connected.

### Output buffer length

The size of a BOOL.

### Input/output buffer

### Input/output buffer length

### Status block

If a request is already pending the new request fails and a STATUS_INVALID_DEVICE_REQUEST message is returned.

## Remarks

This request will complete immediately if the input parameter is TRUE or if the connection status has changed since the last request. Otherwise this request will remain pending until the connection status changes or the request is cancelled.

The audio driver sends this request to get the initial connection status, and sends subsequent requests to be updated when the status changes. The driver stores the connection status in appropriate context data.

When the request completes and indicates a change in the connection status, the audio driver generates the [KSEVENT_PINCAPS_JACKINFOCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-pincaps-jackinfochange) KS event.

When handling the [KSPROPERTY_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description) KS property, the audio driver sets the *IsConnected* member of the [KSJACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksjack-description) structure based on the connection status.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[KSEVENT_PINCAPS_JACKINFOCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-pincaps-jackinfochange)

[KSJACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksjack-description)

[KSPROPERTY_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description)