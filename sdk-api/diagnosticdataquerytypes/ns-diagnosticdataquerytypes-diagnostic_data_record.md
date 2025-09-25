## Description

This resource describes an individual diagnostic data record (event).

## Members

### `rowId`

Type: **[INT64](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The row ID of the record.

### `timestamp`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The timestamp for when the record was processed.

### `eventKeywords`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The keywords associated with this event.

### `fullEventName`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The full event name.

### `providerGroupGuid`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The provider group GUID for this event.

### `producerName`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The name of the producer associated with this event.

### `privacyTags`

Type: **[INT32\*](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
A list of privacy tag IDs for this event.

### `privacyTagCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The number of privacy tags associated with this event.

### `categoryIds`

Type: **[INT32\*](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
A list of the categories associated with this event.

### `categoryIdCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
The number of categories associated with this event.

### `isCoreData`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
`TRUE` if this record is core data. `FALSE` otherwise.

### `extra1`

### `extra2`

### `extra3`

## Remarks

- For more information about events and providers, see [**Event Tracing**](https://learn.microsoft.com/windows/win32/etw/event-tracing-portal).
- For information about how a producer is defined, see [**DIAGNOSTIC_DATA_EVENT_PRODUCER_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_producer_description).
- For information about how a tag is defined, see [**DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description).
- For information about how a category is defined, see [**DIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description).
- For more details on what is core data, see our [**privacy statement**](https://learn.microsoft.com/windows/privacy/windows-diagnostic-data).

## See also