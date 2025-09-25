# EvtFormatMessage function

## Description

Formats a message string.

## Parameters

### `PublisherMetadata` [in]

A handle to the provider's metadata that the [EvtOpenPublisherMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublishermetadata) function returns. The handle acts as a formatting context for the event or message identifier.

You can set this parameter to **NULL** if the Windows Event Collector service forwarded the event. Forwarded events include a **RenderingInfo** section that contains the rendered message strings. You can also set this parameter to **NULL** if the event property that you are formatting is defined in the Winmeta.xml file (for example, if level is set to win:Error). In the latter case, the service uses the Winmeta provider as the formatting context and will format only those message strings that you reference in your event that are defined in the Winmeta.xml file.

### `Event` [in]

A handle to an event. The *Flags* parameter specifies the message string in the event that you want to format. This parameter must be **NULL** if the *Flags* parameter is set to **EvtFormatMessageId**.

### `MessageId` [in]

The resource identifier of the message string that you want to format. To get the resource identifier for a message string, call the [GetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function. Set this parameter only if the *Flags* parameter is set to **EvtFormatMessageId**.

### `ValueCount` [in]

The number of values in the *Values* parameter.

### `Values` [in]

An array of insertion values to use when formatting the event's message string. Typically, you set this parameter to **NULL** and the function gets the insertion values from the event data itself. You would use this parameter to override the default behavior and supply the insertion values to use. For example, you might use this parameter if you wanted to resolve a SID to a principal name before inserting the value.

To override the insertion values, the *Flags* parameter must be set to [EvtFormatMessageEvent](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_format_message_flags), [EvtFormatMessageXML](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_format_message_flags), or [EvtFormatMessageId](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_format_message_flags). If *Flags* is set to [EvtFormatMessageId](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_format_message_flags), the resource identifier must identify the event's message string.

### `Flags` [in]

A flag that specifies the message string in the event to format. For possible values, see the [EVT_FORMAT_MESSAGE_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_format_message_flags) enumeration.

### `BufferSize` [in]

The size of the *Buffer* buffer, in characters.

### `Buffer` [in]

A caller-allocated buffer that will receive the formatted message string. You can set this parameter to **NULL** to determine the required buffer size.

### `BufferUsed` [out]

The size, in characters of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

When the service attempts to find a message for an event, the service looks in the message table resources of the publisher indicated by the *PublisherMetadata* parameter. After the message ID is found, the following search algorithms are used.

For event messages:

1. Search the file specified in **messageFileName** attribute of the [provider](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-provider-eventstype-element) element.
2. If not found, search system messages.

For the Level, Opcode, and Keyword attributes of the [event](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-event-definitiontype-element) element:

1. Search the Winmeta provider resources.
2. Search the file specified in **messageFileName** attribute of the [provider](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-provider-eventstype-element) element.

For the Task attribute of the [event](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-event-definitiontype-element) element:

1. Search the file specified in **messageFileName** attribute of the [provider](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-provider-eventstype-element) element.
2. If not found, search the Winmeta provider resources.

For localizable parameters referenced as %%*n* (where *n* is the message ID) in the event message:

1. Search files listed in **parameterFileName** attribute of the [provider](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-provider-eventstype-element) element from left to right.
2. If not found, search system messages.

#### Examples

For an example that shows how to use this function, see [Formatting Event Messages](https://learn.microsoft.com/windows/desktop/WES/formatting-event-messages) and [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)