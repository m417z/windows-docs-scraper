# CUSTOM_SYSTEM_EVENT_TRIGGER_INIT function

## Description

Initializes the [**_CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_custom_system_event_trigger_config) structure.

## Parameters

### `Config`

A pointer to the [**_CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_custom_system_event_trigger_config) structure to initialize.

### `TriggerId`

A pointer to a Unicode string that contains the GUID used to identify background task to trigger.

## Remarks

## See also

[**_CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_custom_system_event_trigger_config)

[**RtlRaiseCustomSystemEventTrigger**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlraisecustomsystemeventtrigger)