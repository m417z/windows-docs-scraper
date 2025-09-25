## Description

The **STORPORT_ETW_EVENT_CHANNEL** enumeration identifies the event channels of Storport to which miniport can log an event.

## Constants

### `StorportEtwEventDiagnostic`

Storport's diagnostic channel (*Microsoft-Windows-Storage-Storport/Diagnose*).

### `StorportEtwEventOperational`

Storport's operational channel (*Microsoft-Windows-Storage-Storport/Operational*).

### `StorportEtwEventHealth`

Storport's health channel (*Microsoft-Windows-Storage-Storport/Health*).

### `StorportEtwEventIoPerformance`

Reserved for internal use. Do not use.

## Remarks

**STORPORT_ETW_EVENT_CHANNEL** is identified in the **Channel** member of a **[STOR_SET_EVENT_LOGGING](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_set_event_logging)** structure.

## See also

- **[HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)**
- **[STOR_SET_EVENT_LOGGING](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_set_event_logging)**