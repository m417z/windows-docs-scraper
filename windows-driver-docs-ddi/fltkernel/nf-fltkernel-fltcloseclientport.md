# FltCloseClientPort function

## Description

**FltCloseClientPort** closes a communication client port.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `ClientPort` [out]

Pointer to a variable that contains the opaque port handle for the client port to be closed. On return, the variable receives **NULL**. This parameter is required and cannot be **NULL** on input.

## Return value

None

## Remarks

A minifilter driver normally calls **FltCloseClientPort** from the *DisconnectNotifyCallback* routine that it registered when it called [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport). The Filter Manager calls the *DisconnectNotifyCallback* routine whenever the user-mode handle count for the client port reaches zero or when the minifilter driver is about to be unloaded.

**FltCloseClientPort** closes a communication client port that was created by the minifilter driver's *ConnectNotifyCallback* routine.

On input, the *ClientPort* parameter is a pointer to a variable containing the opaque handle for the client port to be closed. To ensure that any messages sent by [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsendmessage) are synchronized properly when the communication client port is being closed, **FltCloseClientPort** sets this variable to **NULL**.

This routine disconnects a specific connection from the minifilter driver. To close the handle for the minifilter driver's server port, which listens for incoming connections, use [FltCloseCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosecommunicationport).

## See also

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FltCloseCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosecommunicationport)

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsendmessage)