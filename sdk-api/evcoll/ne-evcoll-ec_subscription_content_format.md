# EC_SUBSCRIPTION_CONTENT_FORMAT enumeration

## Description

The **EC_SUBSCRIPTION_CONTENT_FORMAT** enumeration specifies how events will be rendered on the computer that sends the events before the events are sent to the event collector computer.

## Constants

### `EcContentFormatEvents:1`

When an event is received, the Event Collector service sends an event as the received event to an event log. The service sends the raw event data only, and not any localized event data.

### `EcContentFormatRenderedText`

When an event is received, the Event Collector service sends an event as rendered text to an event log. The service sends raw event data and localized event information.