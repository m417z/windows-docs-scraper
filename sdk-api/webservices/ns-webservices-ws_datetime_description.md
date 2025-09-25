# WS_DATETIME_DESCRIPTION structure

## Description

This type description is used with [WS_DATETIME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and is optional.
It is used to specify constraints on the set of values
which can be deserialized.

Only the **ticks** member of the [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) is compared.

## Members

### `minValue`

The minimum value.

### `maxValue`

The maximum value.