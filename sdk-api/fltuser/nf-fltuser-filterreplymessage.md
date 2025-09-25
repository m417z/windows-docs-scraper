# FilterReplyMessage function

## Description

The **FilterReplyMessage** function replies to a message from a kernel-mode minifilter.

## Parameters

### `hPort` [in]

Communication port handle returned by a previous call to [FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport). This parameter is required and cannot be **NULL**.

### `lpReplyBuffer` [in]

A pointer to a caller-allocated buffer containing the reply to be sent to the minifilter. The reply must contain a [FILTER_REPLY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_reply_header) structure, but otherwise, its format is caller-defined. This parameter is required and cannot be **NULL**.

### `dwReplyBufferSize` [in]

Size, in bytes, of the buffer that the *lpReplyBuffer* parameter points to. See the Remarks section.

## Return value

**FilterReplyMessage** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

A user-mode application calls the **FilterReplyMessage** function to reply to a message received from a kernel-mode minifilter.

To get a message from a minifilter, call [FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage).

To send a message to a minifilter, call [FilterSendMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtersendmessage).

A minifilter sends a message to a user-mode application by calling [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage).

**Important**

Due to (system-specific) structure [padding](https://learn.microsoft.com/windows-hardware/drivers/) requirements, accuracy is required when you set the size of buffers that are associated with [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage) and **FilterReplyMessage**. As an example, assume data must be sent (via **FilterReplyMessage**) to a minifilter. The user-mode component might declare the following structure to do so:

```cpp
typedef struct _REPLY_STRUCT
{
     FILTER_REPLY_HEADER Header;
     MY_STRUCTURE Data;  // The structure to be sent to the minifilter.
} REPLY_STRUCT, *PREPLY_STRUCT;
```

Given this structure, it might seem obvious that the caller of **FilterReplyMessage** would set the *dwReplyBufferSize* parameter to `sizeof(REPLY_STRUCT)` and the *ReplyLength* parameter of [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage) to the same value. However, because of structure padding idiosyncrasies, `sizeof(REPLY_STRUCT)` might be larger than `sizeof(FILTER_REPLY_HEADER) + sizeof(MY_STRUCT)`. If this is the case, **FltSendMessage** returns STATUS_BUFFER_OVERFLOW.

Therefore, we recommend that you call **FilterReplyMessage** and [FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage) (leveraging the above example) by setting *dwReplyBufferSize* and *ReplyLength* both to `sizeof(FILTER_REPLY_HEADER) + sizeof(MY_STRUCT)` instead of `sizeof(REPLY_STRUCT)`. This ensures that any extra padding at the end of the **REPLY_STRUCT** structure is ignored.

## See also

[FILTER_REPLY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_reply_header)

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage)

[FilterSendMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtersendmessage)

[FltSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltsendmessage)