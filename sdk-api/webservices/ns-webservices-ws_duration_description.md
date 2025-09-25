# WS_DURATION_DESCRIPTION structure

## Description

An optional type description used with [WS_DURATION_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).
It is used to specify constraints on the set of values
which can be deserialized.

## Members

### `minValue`

The minimum value.

### `maxValue`

The maximum value.

### `comparer`

Specifies a function which can be used to compare [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration). If **NULL**, a default
comparer is used.

Because [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration) has a partial ordering, not all durations can be unambiguously compared
(for example, 1 month and 30 days). The default comparer function can compare durations that specify
years and months (but no other components), or durations that specify no years or months (but any other
component).