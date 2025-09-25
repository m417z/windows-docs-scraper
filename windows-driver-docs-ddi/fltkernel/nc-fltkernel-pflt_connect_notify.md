## Description

*FltMgr* calls a minifilter's **ConnectNotifyCallback** callback function to notify the minifilter when a new connection to a communication port is being requested.

## Parameters

### `ClientPort`

[in] Opaque, *FltMgr*-generated handle for the new client port that is being established between the user-mode application and the kernel-mode minifilter.

The minifilter must pass this handle as the **ClientPort** parameter to [**FltSendMessage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsendmessage) when sending and replying to messages on this client port.

The minifilter must eventually call [**FltCloseClientPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcloseclientport) to close this client port, typically from its [**DisconnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_disconnect_notify) routine.

**ClientPort** isn't the same as the **ServerPort** handle return by[**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport).

### `ServerPortCookie`

[in] Pointer to context information defined by the minifilter. The minifilter can use this information to distinguish among multiple communication server ports that it might create. When the server port was created, the minifilter driver passed this context pointer as the **ServerPortCookie** parameter to **FltCreateCommunicationPort**.

### `ConnectionContext`

[in] Context information pointer that the user-mode application passed in the **lpContext** parameter to [**FilterConnectCommunicationPort**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterconnectcommunicationport).

### `SizeOfContext`

[in] Size, in bytes, of the buffer that **ConnectionContext** points to.

### `ConnectionPortCookie`

[out] Pointer to the miniport's information that uniquely identifies this client port. The minifilter can use this cookie to identify the connection when *FltMgr* passes it in subsequent calls to [**MessageNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_message_notify) and [**DisconnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_disconnect_notify).

## Return value

**ConnectNotifyCallback** returns STATUS_SUCCESS if the operation succeeds and the connection has been accepted. Otherwise, it returns an appropriate NTSTATUS value such as:

| Return code | Meaning |
| ----------- | ------- |
| STATUS_INSUFFICIENT_RESOURCES | There aren't enough resources to complete the operation. |
| STATUS_INVALID_PARAMETER | One or more of the input parameters are invalid. |

## Remarks

*FltMgr* calls this routine whenever a user-mode application calls [**FilterConnectCommunicationPort**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterconnectcommunicationport) to send a connection request to the minifilter driver.

The minifilter should perform any necessary validation of the connection attempt.

For more information, see [Communication between user-mode and minifilters](https://learn.microsoft.com/windows-hardware/drivers/ifs/communication-between-user-mode-and-kernel-mode).

## See also

[**FilterConnectCommunicationPort**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[**FltCloseClientPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcloseclientport)

[**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[**FltSendMessage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsendmessage)

[**DisconnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_disconnect_notify)

[**MessageNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_message_notify)