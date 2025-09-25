# TdhGetEventMapInformation function

## Description

Retrieves information about the event map contained in the event.

## Parameters

### `pEvent` [in]

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback. For details, see the [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) structure.

### `pMapName` [in]

Null-terminated Unicode string that contains the name of the map attribute value. The name comes from the **MapNameOffset** member of the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structure.

### `pBuffer` [out]

User-allocated buffer to receive the event map. The map could be a value map, bitmap, or pattern map. For details, see the [EVENT_MAP_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_map_info) structure.

### `pBufferSize` [in, out]

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *pBuffer* buffer is too small. Use the required buffer size set in *pBufferSize* to allocate a new buffer. |
| **ERROR_NOT_FOUND** | The schema for the event was not found or the specified map was not found. |
| **ERROR_FILE_NOT_FOUND** | The **resourceFileName** attribute in the manifest contains the location of the provider binary. When you register the manifest, the location is written to the registry. TDH was unable to find the binary based on the registered location. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_WMI_SERVER_UNAVAILABLE** | The WMI service is not available. |

## Remarks

You cannot use this function to retrieve event map information for WPP events.

For maps defined in a manifest, the string will contain a space at the end of the string. For example, if the value is mapped to "Monday" in the manifest, the string is returned as "Monday ".

#### Examples

For an example that shows how to call this function, see [Using TdhGetProperty to Consume Event Data](https://learn.microsoft.com/windows/desktop/ETW/using-tdhgetproperty-to-consume-event-data).