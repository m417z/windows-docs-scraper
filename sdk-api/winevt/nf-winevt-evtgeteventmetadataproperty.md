# EvtGetEventMetadataProperty function

## Description

Gets the specified event metadata property.

## Parameters

### `EventMetadata` [in]

A handle to the event metadata that the [EvtNextEventMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnexteventmetadata) function returns.

### `PropertyId` [in]

The identifier of the metadata property to retrieve. For a list of property identifiers, see the [EVT_EVENT_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_event_metadata_property_id) enumeration.

### `Flags` [in]

Reserved. Must be zero.

### `EventMetadataPropertyBufferSize` [in]

The size of the *EventMetadataPropertyBuffer* buffer, in bytes.

### `EventMetadataPropertyBuffer` [in]

A caller-allocated buffer that will receive the metadata property. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `EventMetadataPropertyBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## See also

[EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty)

[EvtNextEventMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnexteventmetadata)