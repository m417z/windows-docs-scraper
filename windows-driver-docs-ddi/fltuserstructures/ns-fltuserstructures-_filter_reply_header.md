# _FILTER_REPLY_HEADER structure

## Description

The FILTER_REPLY_HEADER structure contains message reply header information.

## Members

### `Status`

Status value to be returned for the original message.

### `MessageId`

Unique ID received in the **MessageId** field of the original message.

## Remarks

This structure is allocated by a user-mode application. It is a container for a reply that the application sends in response to a message received from a kernel-mode minifilter or minifilter instance.

## See also

[FILTER_MESSAGE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_message_header)

[FilterReplyMessage](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterreplymessage)