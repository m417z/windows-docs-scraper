# EVT_FORMAT_MESSAGE_FLAGS enumeration

## Description

Defines the values that specify the message string from the event to format.

## Constants

### `EvtFormatMessageEvent:1`

Format the event's message string.

### `EvtFormatMessageLevel`

Format the message string of the level specified in the event.

### `EvtFormatMessageTask`

Format the message string of the task specified in the event.

### `EvtFormatMessageOpcode`

Format the message string of the opcode specified in the event.

### `EvtFormatMessageKeyword`

Format the message string of the keywords specified in the event. If the event specifies multiple keywords, the formatted string is a list of null-terminated strings. Increment through the strings until your pointer points past the end of the used buffer.

### `EvtFormatMessageChannel`

Format the message string of the channel specified in the event.

### `EvtFormatMessageProvider`

Format the provider's message string.

### `EvtFormatMessageId`

Format the message string associated with a resource identifier. The provider's metadata contains the resource identifiers; the message compiler assigns a resource identifier to each string when it compiles the manifest.

### `EvtFormatMessageXml`

Format all the message strings in the event. The formatted message is an XML string that contains the event details and the message strings. The message strings are included in the [RenderingInfo](https://learn.microsoft.com/windows/desktop/WES/eventschema-renderingtype-complextype) section of the event details.

## See also

[EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage)