# IOCTL_BTHHFP_STREAM_GET_STATUS_UPDATE IOCTL

## Description

The **IOCTL_BTHHFP_STREAM_GET_STATUS_UPDATE**
IOCTL Gets a stream channel status update.

## Parameters

### Major code

### Input buffer

A BOOL that is set to TRUE to request an immediate update. Otherwise, set this to FALSE.

### Input buffer length

The size of a BOOL.

### Output buffer

An NT_STATUS value that represents the new stream channel status. An error status indicates that the synchronous connection-oriented (SCO) channel associated with the stream has been closed, and cannot be reestablished.

### Output buffer length

The size of an NT_STATUS object.

### Input/output buffer

### Input/output buffer length

### Status block

If a request is already pending, then the new request fails and a STATUS_INVALID_DEVICE_REQUEST message is returned.

If a request is pending when an IOCTL_BTHHFP_CLOSE_STREAM_CHANNEL request occurs, then the pending request is canceled and the I/O status block shows STATUS_CANCELLED.

## Remarks

This request will complete immediately if the input parameter is TRUE or if the stream channel status has changed since the last request. Otherwise this request will remain pending until the stream channel status changes or the request is cancelled.

This request is valid only between a successful [IOCTL_BTHHFP_STREAM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_stream_open) request and subsequent [IOCTL_BTHHFP_STREAM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_stream_close) request. If this request is pending when the stream is closed by an **IOCTL_BTHHFP_STREAM_CLOSE** request, then the pending request is cancelled.

An error status can occur when the Bluetooth link is dropped or other similar conditions occur. Although such conditions are rare, the audio driver must be developed to handle them. This error status can often occur almost simultaneously with a connection status change to FALSE. However the audio driver should not rely on this change of status as a way to determine whether or not the Bluetooth link has been dropped.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)