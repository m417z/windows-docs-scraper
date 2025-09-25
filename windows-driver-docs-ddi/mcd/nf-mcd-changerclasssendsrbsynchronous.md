# ChangerClassSendSrbSynchronous function

## Description

The **ChangerClassSendSrbSynchronous** routine synchronously sends an SRB to a specified device.

## Parameters

### `DeviceObject` [in]

Pointer to the functional device object of the target device.

### `Srb` [in]

Pointer to a partially initialized SCSI request block (SRB) to be sent to the target device.

### `Buffer` [in]

Specifies address of the buffer that *Srb->***DataBuffer** should point to. **ChangerClassSendSrbSynchronous** creates an MDL for this buffer and passes it to the target device driver in the SRB IRP.

### `BufferSize` [in]

Specifies length, in bytes, of the buffer.

### `WriteToDevice` [in]

Indicates a write operation when **TRUE** and read operation when **FALSE**.

## Return value

Returns STATUS_SUCCESS if the SRB is transmitted successfully or the appropriate error code if the SRB fails or cannot be sent for some reason.

## Remarks

Changer miniclass drivers can call this class driver routine in Microsoft Windows XP and later operating systems. Miniclass drivers should use this routine to send an SRB to the port driver instead of calling the *classpnp.sys* library routine **ClassSendSrbSynchronous** directly. Although *classpnp.sys* is shipped with the Windows Driver Kit (WDK), it is not a supported API, and drivers that call this library's routines directly might not function properly in future releases.

**ChangerClassSendSrbSynchronous** finishes the initialization of the partially initialized SRB, setting the SRB's flags with the values indicated in the target's device object. **ChangerClassSendSrbSynchronous** creates the IRP that is used to convey the SRB to the target device, sends the IRP, then handles the IRP's completion.

If the IRP fails and the sense request data indicates that the IRP should be retried, **ChangerClassSendSrbSynchronous** will resend the IRP.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)