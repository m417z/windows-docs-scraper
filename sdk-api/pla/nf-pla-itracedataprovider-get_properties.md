# ITraceDataProvider::get_Properties

## Description

Retrieves the list of extended data items that Event Tracing for Windows (ETW) includes with the event.

This property is read-only.

## Parameters

## Remarks

Use this property to request the following data items with the event.

| Data item | Description |
| --- | --- |
| Sid (value 0x01) | Includes the user's security identifier. |
| SessionId (value 0x02) | Includes the session identifier. |
| StackTrace (value 0x04) | Includes the stack trace. |

Use the [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface to retrieve or specify the extended data items. The [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property contains items that are combined by using the **OR** operator. The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the string representation of the extended data item. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the extended data item value.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)