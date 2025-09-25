# STOR_EVENT_TYPE enumeration

## Description

The **STOR_EVENT_TYPE** enum identifies the type of event object initialized by a miniport.

## Constants

### `StorNotificationEvent`

The event is a notification event.

### `StorSynchronizationEvent`

The event is a synchronization event.

## Remarks

A miniport initializes an event object by calling [**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent), passing in a **STOR_EVENT_TYPE** enum to identify the type of the event object.

## See also

[**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent)