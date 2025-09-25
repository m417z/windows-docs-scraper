# PROVIDER_FIELD_INFOARRAY structure

## Description

Defines metadata information about the requested field.

## Members

### `NumberOfElements`

Number of elements in the **FieldInfoArray** array.

### `FieldType`

Type of field information in the **FieldInfoArray** array. For possible values, see the [EVENT_FIELD_TYPE](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-event_field_type) enumeration.

### `FieldInfoArray`

Array of [PROVIDER_FIELD_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_field_info) structures that define the field's name, description and value.

## See also
[TdhEnumerateProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfieldinformation)

[TdhQueryProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhqueryproviderfieldinformation)