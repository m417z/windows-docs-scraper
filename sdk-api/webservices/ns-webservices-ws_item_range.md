# WS_ITEM_RANGE structure

## Description

Defines the minimum and maximum number of items that may appear
when using [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping),
**WS_REPEATING_ELEMENT_CHOICE_FIELD_MAPPING**,
or **WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING** within
a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description). The constraint is only
enforced during deserialization.

## Members

### `minItemCount`

The minimum number of elements that must appear.

### `maxItemCount`

The maximum number of items that may appear.