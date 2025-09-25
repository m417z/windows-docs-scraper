# TdhGetPropertySize function

## Description

Retrieves the size of one or more property values in the event data.

## Parameters

### `pEvent` [in]

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback. For details, see the [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) structure.

### `TdhContextCount` [in]

Number of elements in *pTdhContext*.

### `pTdhContext` [in]

Array of context values for WPP or classic ETW events only, otherwise, **NULL**. For details, see the [TDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context) structure. The array must not contain duplicate context types.

### `PropertyDataCount` [in]

Number of data descriptor structures in *pPropertyData*.

### `pPropertyData` [in]

Array of [PROPERTY_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-property_data_descriptor) structures that define the property whose size you want to retrieve.

You can pass this same array to the [TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty) function to retrieve the property data.

If you are retrieving the size of a property that is not a member of a structure, you can specify a single data descriptor. If you are retrieving the size of a property that is a member of a structure, specify an array of two data descriptors (structures cannot contain or reference other structures). For more information on specifying this parameter, see the example code below.

### `pPropertySize` [out]

Size of the property, in bytes. Use this value to allocate the buffer passed in the *pBuffer* parameter of the [TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty) function.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_FOUND** | The schema for the event was not found or the specified map was not found.<br><br>If you used a MOF class to define your event, TDH looks for the schema in the WMI repository. If you used a manifest to define your event, TDH looks in the provider's resources. If you use a manifest, the **resourceFileName** attribute of the **provider** element defines the location where TDH expects to find the resources. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_FILE_NOT_FOUND** | The **resourceFileName** attribute in the manifest contains the location of the provider binary. When you register the manifest, the location is written to the registry. TDH was unable to find the binary based on the registered location. |
| **ERROR_WMI_SERVER_UNAVAILABLE** | The WMI service is not available. |

## Remarks

If the event is a WPP or classic ETW event, you can specify context information that is used to help parse the event information. The event is a WPP event if the EVENT_HEADER_FLAG_TRACE_MESSAGE flag is set in the **Flags** member of [EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) (see the **EventHeader** member of [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)). The event is a legacy ETW event if the EVENT_HEADER_FLAG_CLASSIC_HEADER flag is set.

#### Examples

For an example that shows how to call this function, see [Using TdhGetProperty to Consume Event Data](https://learn.microsoft.com/windows/desktop/ETW/using-tdhgetproperty-to-consume-event-data).

## See also
[TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty)