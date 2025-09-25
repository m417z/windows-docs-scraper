# PROVIDER_FILTER_INFO structure

## Description

Defines a filter and its data.

## Members

### `Id`

The filter identifier that identifies the filter in the manifest. This is the same value as the **value** attribute of the [FilterType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-filtertype-complextype) complex type.

### `Version`

The version number that identifies the version of the filter definition in the manifest. This is the same value as the **version** attribute of the [FilterType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-filtertype-complextype) complex type.

### `MessageOffset`

Offset from the beginning of this structure to the message string that describes the filter. This is the same value as the **message** attribute of the [FilterType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-filtertype-complextype) complex type.

### `Reserved`

Reserved.

### `PropertyCount`

The number of elements in the *EventPropertyInfoArray* array.

### `EventPropertyInfoArray`

An array of [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structures that define the filter data.

## See also
[TdhEnumerateProviderFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfilters)