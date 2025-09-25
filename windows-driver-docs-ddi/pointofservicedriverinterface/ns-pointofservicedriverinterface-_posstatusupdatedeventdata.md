# _PosStatusUpdatedEventData structure

## Description

This structure contains data passed to the [StatusUpdated](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn790040(v=vs.85)) event.

## Members

### `Header`

A [PosEventDataHeader](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn772232(v=vs.85)) structure that contains information about the event that was raised and the amount of memory, in bytes, that this event data uses.

### `Status`

Indicates a device-specific enumeration value.

### `ExtendedStatus`

Indicates a driver-specific value intended to be used by the vendor for diagnostic purposes.