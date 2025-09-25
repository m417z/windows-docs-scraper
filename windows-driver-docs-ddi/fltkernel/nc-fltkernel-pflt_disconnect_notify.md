## Description

*FltMgr* calls a minifilter's **DisconnectNotifyCallback** callback function to notify the minifilter when a client port is being disconnected.

## Parameters

### `ConnectionCookie`

[in] Pointer to minifilter-defined information that uniquely identifies this client port. When the client port was created, the minifilter returned this context pointer in the **ConnectionPortCookie** parameter of its [**ConnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_connect_notify) routine.

## Remarks

*FltMgr* calls **DisconnectNotifyCallback** whenever the user-mode handle count for the client port reaches zero or when the minifilter is about to be unloaded.

For more information, see [Communication between user-mode and minifilters](https://learn.microsoft.com/windows-hardware/drivers/ifs/communication-between-user-mode-and-kernel-mode).

## See also

[**ConnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_connect_notify)

[**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)