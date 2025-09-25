# FilterGetMessage function

## Description

The **FilterGetMessage** function gets a message from a kernel-mode minifilter.

## Parameters

### `hPort` [in]

Communication port handle returned by a previous call to [FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport). This parameter is required and cannot be **NULL**.

### `lpMessageBuffer` [out]

Pointer to a caller-allocated buffer that receives the message from the minifilter. The message must contain a [FILTER_MESSAGE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_message_header) structure, but otherwise its format is caller-defined. This parameter is required and cannot be **NULL**.

### `dwMessageBufferSize` [in]

Size, in bytes, of the buffer that the *lpMessageBuffer* parameter points to.

### `lpOverlapped` [in, out]

Pointer to an OVERLAPPED structure. This parameter is optional and can be **NULL**. If it is not **NULL**, the caller must initialize the **hEvent** member of the OVERLAPPED structure to a valid event handle or **NULL**.

## Return value

**FilterGetMessage** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

The **FilterGetMessage** function is designed for both synchronous and asynchronous (overlapped) operation.

When *lpOverlapped* is **NULL**, and a message is available, **FilterGetMessage** returns immediately. Otherwise, the caller is put into a wait state until a message is received.

If *lpOverlapped* is not **NULL**, **FilterGetMessage** returns ERROR_IO_PENDING. In this situation, the event object in the *lpOverlapped* structure is set to the nonsignaled state before **FilterGetMessage** returns. When the message is delivered, this event is set to the signaled state.

After receiving the message from the minifilter, the caller can send a reply by calling [FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage).

A minifilter or instance sends a message to a user-mode application by calling [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage).

## See also

[CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa)

[FILTER_MESSAGE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_message_header)

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage)

[FilterSendMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtersendmessage)

[FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage)

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted)