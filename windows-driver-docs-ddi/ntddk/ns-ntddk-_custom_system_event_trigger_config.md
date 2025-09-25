# _CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG structure

## Description

Contains information about a custom system event trigger. This structure is used by [**RtlRaiseCustomSystemEventTrigger**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlraisecustomsystemeventtrigger).

## Members

### `Size`

The size of the structure in bytes.

### `TriggerId`

A pointer to a Unicode string that contains the GUID used to identify background task to trigger.

## Remarks

To initialize this structure, call [**CUSTOM_SYSTEM_EVENT_TRIGGER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-custom_system_event_trigger_init).

## See also

[**RtlRaiseCustomSystemEventTrigger**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlraisecustomsystemeventtrigger)

[**CUSTOM_SYSTEM_EVENT_TRIGGER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-custom_system_event_trigger_init)