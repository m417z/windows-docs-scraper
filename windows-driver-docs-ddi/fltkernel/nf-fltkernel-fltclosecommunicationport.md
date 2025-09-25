# FltCloseCommunicationPort function

## Description

**FltCloseCommunicationPort** closes a minifilter driver's communication server port.

## Parameters

### `ServerPort` [in]

Opaque port handle for the server port to be closed. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

**FltCloseCommunicationPort** closes a communication server port that was created by a previous call to [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport).

A minifilter driver normally calls **FltCloseCommunicationPort** from its *FilterUnloadCallback* ([PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)) routine.

After **FltCloseCommunicationPort** is called, the opaque port handle specified by the *ServerPort* parameter is no longer valid and cannot safely be used. (The *ServerPort* handle is for the communication server port that the minifilter driver uses to listen for incoming connections.)

When the communication server port is closed, existing connections are not affected. However, no more incoming connections will be accepted.

This routine closes handle for the minifilter driver's server port, which listens for incoming connections. To disconnect a specific connection from the minifilter driver, use [FltCloseClientPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcloseclientport).

## See also

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FltCloseClientPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcloseclientport)

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsendmessage)

[PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)