## Description

*FltMgr* calls a minifilter's **MessageNotifyCallback** callback function whenever a user-mode application calls [**FilterSendMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtersendmessage) to send a message to the minifilter through the client port.

## Parameters

### `PortCookie`

[in] Pointer to minifilter-defined information that uniquely identifies this client port. When the client port was created, the minifilter returned this context pointer in the **ConnectionPortCookie** parameter of its [**ConnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_connect_notify) routine.

### `InputBuffer`

[in] Pointer to a caller-allocated buffer containing the message to be sent to the minifilter.

**InputBuffer** is a pointer to a raw, unlocked user-mode buffer. This pointer is valid only in the context of the user-mode process and must only be accessed from within a **try/except** block.

*FltMgr* calls [**ProbeForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread) to validate this pointer, but it doesn't ensure that the buffer is properly aligned. If the buffer contains structures that have alignment requirements, the minifilter is responsible for performing any necessary alignment checks. To do this, the minifilter can use the [**IS_ALIGNED**](https://learn.microsoft.com/previous-versions/ff549486(v=vs.85)) macro as shown in the [MiniSpy](https://github.com/microsoft/windows-driver-samples/tree/main/filesys/miniFilter/minispy) sample minifilter.

This parameter is optional and can be NULL.

### `InputBufferLength`

[in] Size, in bytes, of the buffer that **InputBuffer** points to. This parameter is ignored if **InputBuffer** is NULL.

### `OutputBuffer`

[out] Pointer to a caller-allocated buffer that receives the reply, if any, from the minifilter.

**OutputBuffer** is a pointer to a raw, unlocked user-mode buffer. This pointer is valid only in the context of the user-mode process and must only be accessed from within a **try/except** block.

*FltMgr* calls [**ProbeForWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforwrite) to validate this pointer, but it doesn't ensure that the buffer is properly aligned. If the buffer contains structures that have alignment requirements, the minifilter is responsible for performing any necessary alignment checks. To do this, the minifilter can use the [**IS_ALIGNED**](https://learn.microsoft.com/previous-versions/ff549486(v=vs.85)) macro as shown in the [MiniSpy](https://github.com/microsoft/windows-driver-samples/tree/main/filesys/miniFilter/minispy) sample minifilter.

This parameter is optional and can be NULL.

### `OutputBufferLength`

[in] Size, in bytes, of the buffer that **OutputBuffer** points to. This parameter is ignored if **OutputBuffer** is NULL.

### `ReturnOutputBufferLength`

[out] Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that **OutputBuffer** points to.

## Return value

**MessageNotifyCallback** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS value such as:

| Return code | Meaning |
| ----------- | ------- |
| STATUS_INSUFFICIENT_RESOURCES | There aren't enough resources to complete the operation. |
| STATUS_INVALID_PARAMETER | One or more of the input parameters are invalid. |

## Remarks

Minifilters can optionally implement **MessageNotifyCallback**. If a minifilter doesn't implement this callback, any request made from user mode to send data to the port will receive an error.

For more information, see [Communication between user-mode and minifilters](https://learn.microsoft.com/windows-hardware/drivers/ifs/communication-between-user-mode-and-kernel-mode).

## See also

[**ConnectNotifyCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_connect_notify)

[**FilterSendMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtersendmessage)

[**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)