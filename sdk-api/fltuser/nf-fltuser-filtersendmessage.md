# FilterSendMessage function

## Description

The **FilterSendMessage** function sends a message to a kernel-mode minifilter.

## Parameters

### `hPort` [in]

Communication port handle returned by a previous call to [FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport). This parameter is required and cannot be **NULL**.

### `lpInBuffer` [in, optional]

Pointer to a caller-allocated buffer containing the message to be sent to the minifilter. The message format is caller-defined. This parameter is required and cannot be **NULL**.

### `dwInBufferSize` [in]

Size, in bytes, of the buffer pointed to by *lpInBuffer*.

### `lpOutBuffer` [out]

Pointer to a caller-allocated buffer that receives the reply (if any) from the minifilter.

### `dwOutBufferSize` [in]

Size, in bytes, of the buffer pointed to by *lpOutBuffer*. This value is ignored if *lpOutBuffer* is **NULL**.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpOutBuffer* points to if the call to **FilterSendMessage** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterSendMessage** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

The **FilterSendMessage** function sends a message to a minifilter. The message is passed to the minifilter's message notification callback routine, which processes the message. (The minifilter registers its message callback notification routine by passing it as the *MessageNotifyCallback* parameter to [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatecommunicationport).)

**FilterSendMessage** is synchronous. The caller is put into a wait state until the message is delivered and the minifilter's reply (if any) is received.

If the caller expects a reply, it must pass a non-**NULL** buffer for the *lpOutBuffer* parameter and a positive value for the *dwOutBufferSize* parameter.

To get a message from a minifilter, call [FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage).

To reply to a message from a minifilter, call [FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage).

A minifilter sends a message to a user-mode application by calling [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage).

## See also

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage)

[FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage)

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage)