# EventRegistrationToken structure (eventtoken.h)

## Description

Defines an event handler that has been registered with an event source.

## Members

### `value`

Type: **INT64**

An identifying value that is provided by an event source.

## Remarks

Use an **EventRegistrationToken** to unsubscribe from a Windows Runtime event source.

You acquire an **EventRegistrationToken** when you subscribe to an event.

## See also

[IEventHandler\ interface](https://learn.microsoft.com/previous-versions/hh438424(v=vs.85))