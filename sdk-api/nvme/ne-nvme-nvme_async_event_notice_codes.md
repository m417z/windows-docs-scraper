# NVME_ASYNC_EVENT_NOTICE_CODES enumeration

## Description

Contains values that indicate a Notice event type.

## Constants

### `NVME_ASYNC_NOTICE_NAMESPACE_ATTRIBUTE_CHANGED`

The [Identify Namespace data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) for one or more namespaces has changed.

Host software may use this event as an indication that it should read the [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structures for each namespace to determine what has changed.

A controller should not send this event when [Namespace Utilization (NUSE)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) has changed, as this is a frequent event that does not require action by the host. A controller should only send this event for changes to the [Format Progress Indicator (FPI)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) field when bits `6:0` of that field transition from a non-zero value to zero or from a zero value to a non-zero value.

### `NVME_ASYNC_NOTICE_FIRMWARE_ACTIVATION_STARTING`

The controller is starting a firmware activation process during which command processing is paused.

Host software may use the Processing Paused (PP) field of [NVME_CONTROLLER_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_status) to determine when command processing has resumed. To clear this event, the host software reads the [Firmware Slot Information log page](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_firmware_slot_info_log).

### `NVME_ASYNC_NOTICE_TELEMETRY_LOG_CHANGED`

The controller has saved the controller internal state in the Telemetry Controller-Initiated log page and set the Telemetry Controller-Initiated Data Available field to 1h in that log page. To clear this event, the host issues a Get Log Page command with Retain Asynchronous Event bit cleared to ‘0’ for the Telemetry Controller-Initiated log.

## Remarks

Use this enumeration to specify values in the **NVME_ASYNC_EVENT_TYPE_NOTICE** field of the [NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types) enumeration that is used in the Async Event Request Admin command.

## See also

[NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types)
[NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)
[NVME_FIRMWARE_SLOT_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_firmware_slot_info_log)
[NVME_ADMIN_COMMANDS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands)