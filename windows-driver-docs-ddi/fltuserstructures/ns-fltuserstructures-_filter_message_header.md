# _FILTER_MESSAGE_HEADER structure

## Description

The FILTER_MESSAGE_HEADER structure contains message header information.

## Members

### `ReplyLength`

On output from [FilterGetMessage](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage), this field receives the length, in bytes, of the expected reply, including the FILTER_REPLY_HEADER header. Set to zero if no reply is expected.

### `MessageId`

On output from [FilterGetMessage](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage), this field receives the unique identifier (ID) for the message sent by the kernel-mode driver. If the application replies to the message, it must set this ID in the **MessageId** field of the FILTER_REPLY_HEADER header in the reply.

## Remarks

To receive messages from a kernel-mode minifilter, a user-mode application typically defines a custom message structure. This structure typically consists of this header structure, followed by an application-defined structure to hold the actual message data.

## See also

[FILTER_REPLY_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_reply_header)

[FilterGetMessage](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetmessage)