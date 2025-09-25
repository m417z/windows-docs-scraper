# RtlRaiseCustomSystemEventTrigger function

## Description

Allows NT services and kernel-mode and user-mode drivers to raise a custom trigger for a device. A custom trigger, owned by the driver developer, notifies system event broker to start an associated background task with it, which is identified by a custom trigger identifier.

## Parameters

### `TriggerConfig` [_In_]

A pointer to a [**_CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_custom_system_event_trigger_config) structure that contains the trigger identifier. Call [**CUSTOM_SYSTEM_EVENT_TRIGGER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-custom_system_event_trigger_init) to initialize the structure before calling the function.

## Return value

This function returns STATUS_SUCCESS if the custom trigger was raised. Otherwise, an appropriate [NTSTATUS Value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) is returned.

| Error code | Description |
| ----------------------------- | ------------------------------------------- |
| STATUS_UNSUCCESSFUL | Another active custom trigger being raised. |
| STATUS_INSTANCE_NOT_AVAILABLE | No subscribers are present. |

## Remarks

## See also

[**_CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_custom_system_event_trigger_config)
[**CUSTOM_SYSTEM_EVENT_TRIGGER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-custom_system_event_trigger_init)