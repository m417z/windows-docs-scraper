# WS_DURATION_COMPARISON_CALLBACK callback function

## Description

Compares two durations.A duration represents a unit of time as an eight-dimensional space where the coordinates designate the year, month, day, hour, minute, second, millisecond, and CPU tick as represented by the [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration) data structure.

## Parameters

### `duration1` [in]

A pointer to a [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration) structure representing the first duration to compare.

### `duration2` [in]

A pointer to a [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration) structure representing the second duration.

### `result` [out]

The relationship between the durations as one of the following values:

* -1 if *duration1* is less than *duration2*
* 0 if *duration1* is equal to *duration2*
* 1 if *duration1* is greater than *duration2*

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) handle where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

If the function cannot compare the specified durations, it should return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)