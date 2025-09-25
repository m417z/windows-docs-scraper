# ValueMapType enumeration

## Description

Defines the type of the value.

## Constants

### `plaIndex:1`

Only one item in the collection can be enabled. The enabled item is the value of the [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value) property. If more than one item is enabled, the first enabled item is used as the value.

### `plaFlag:2`

One or more items in the collection can be enabled. An item in the collection represents a single bit flag. The enabled items in the collection are combined with the **OR** operator to become the value of [IValueMap::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_value).

### `plaFlagArray:3`

The collection contains a list of Event Tracing for Windows extended flags (see the [ITraceDataProvider::Properties](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-get_properties) property).

### `plaValidation:4`

The collection contains a list of HRESULT values returned by the validation process.

## See also

[IValueMap::ValueMapType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_valuemaptype)

[IValueMapItem::ValueMapType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_valuemaptype)