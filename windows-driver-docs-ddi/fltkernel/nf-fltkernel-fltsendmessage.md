# FltSendMessage function

## Description

**FltSendMessage** sends a message to a waiting user-mode application on behalf of a minifilter driver or a minifilter driver instance.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and can't be NULL.

### `ClientPort` [in]

Pointer to a variable that contains the opaque client port pointer for the connection port between the user-mode application and the kernel-mode minifilter driver. For more information about the client port pointer, see the description of the **ConnectNotifyCallback** parameter in the reference entry for [**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport).

### `SenderBuffer` [in]

Pointer to a minifilter-allocated buffer containing the message to send to the user-mode application. This parameter is required and can't be NULL.

### `SenderBufferLength` [in]

Size, in bytes, of the buffer that **SenderBuffer** points to. See **Remarks** for more information.

### `ReplyBuffer` [out, optional]

Pointer to a miniport-allocated buffer that receives a reply from the application, if any. This parameter is optional and can be NULL.

### `ReplyLength` [in, out]

Size, in bytes, of the buffer that **ReplyBuffer** points to. This parameter is optional, but must be non-NULL when **ReplyBuffer** isn't NULL.

### `Timeout` [in, optional]

A pointer to a timeout value that specifies the total absolute or relative length of time, in units of 100 nanoseconds, for which the caller (miniport) can be put into a wait state until the message is received by the user-mode application and until it receives a reply if a reply is expected.

A positive value specifies an absolute time, relative to January 1, 1601. A negative value specifies an interval relative to the current time. Set **Timeout** to NULL if the caller can be put into a wait state indefinitely.

## Return value

**FltSendMessage** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_OVERFLOW | A miniport-allocated buffer wasn't large enough. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | **FltSendMessage** encountered a pool allocation failure. This is an error code. |
| STATUS_PORT_DISCONNECTED | The communication port has been disconnected. This is an error code. |
| STATUS_THREAD_IS_TERMINATING | The wait was interrupted because the thread has been terminated by an application or user. |
| STATUS_TIMEOUT | The **Timeout** interval expired before the message could be delivered or before a reply was received. This is a success code. |

## Remarks

**FltSendMessage** sends a message to a user-mode application on behalf of a minifilter driver or a minifilter driver instance.

If the application calls [**FilterGetMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage) to get the message before the minifilter driver calls **FltSendMessage** to send it, the message that **SendBuffer** points to is delivered immediately when **FltSendMessage** is called. This is typically the case when the application calls **FilterGetMessage** from inside a message loop.

Otherwise, if an application has not called to get a message, *FltMgr* puts the minifilter into a wait state as follows:

* If **Timeout** points to a nonzero value and the application calls [**FilterGetMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage) before the **Timeout** interval expires, the message is delivered.

* If **Timeout** points to a nonzero value and the application doesn't call **FilterGetMessage** before the **Timeout** interval expires, the message isn't delivered and **FltSendMessage** returns STATUS_TIMEOUT as a success code.

* If **Timeout** points to zero (```*Timeout == 0```), **FltSendMessage** returns without waiting.

* If **Timeout** is NULL (```Timeout == NULL```), the minifilter is put into a wait state indefinitely. When the application calls **FilterGetMessage**, the message is delivered.

After the message is delivered, if **ReplyBuffer** is NULL, **FltSendMessage** returns STATUS_SUCCESS.

Otherwise, if **ReplyBuffer** isn't NULL, the minifilter is put into a wait state as follows:

* If **Timeout** is nonzero and the application calls [**FilterReplyMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterreplymessage) before the **Timeout** interval expires, the minifilter receives the reply, and **FltSendMessage** returns STATUS_SUCCESS.

* If **Timeout** is nonzero and the minifilter doesn't receive a reply before the **Timeout** interval expires, **FltSendMessage** returns STATUS_TIMEOUT as a success code.

* If **Timeout** points to zero (```*Timeout == 0```), **FltSendMessage** returns without waiting.

* If **Timeout** is zero when the minifilter is waiting for the reply, the minifilter is put into a wait state indefinitely. When the application calls **FilterReplyMessage**, the minifilter receives the reply, and **FltSendMessage** returns STATUS_SUCCESS.

### Padding and Buffer Size

Problems can occur when the caller doesn't properly account for system-specific structure padding that might occur.

For example, say a minifilter declares the following structure in which to receive a reply, and passes a pointer to it in **ReplyBuffer**:

``` C
typedef struct _REPLY_STRUCT
{
    FILTER_REPLY_HEADER Header;
    REPLY_DATA Data;  // The structure to be sent to the minifilter with the reply.
} REPLY_STRUCT, *PREPLY_STRUCT;
```

**ReplyBuffer** must be allocated with sufficient space to hold the entire structure including any padding. Therefore, ReplyLength should be set to ```sizeof(REPLY_STRUCT)```, not ```sizeof(FILTER_REPLY_HEADER) + sizeof(REPLY_DATA)```.

Setting **ReplyLength** to ```sizeof(FILTER_REPLY_HEADER) + sizeof(REPLY_DATA)``` doesn't account for padding that might be inserted between the **Header** and **Data** members. This can lead to **FltSendMessage** returning STATUS_BUFFER_OVERFLOW even when the buffer is large enough to hold both structures.

After **FltSendMessage** returns successfully, use ```offsetof(REPLY_STRUCT, Data)``` to locate the beginning of the **Data** structure within **ReplyBuffer**, and examine the **ReplyLength** output value to determine the actual number of bytes written by the user-mode application.

## See also

[**FilterGetMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage)

[**FilterReplyMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterreplymessage)

[**FilterSendMessage**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtersendmessage)

[**FltCreateCommunicationPort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)