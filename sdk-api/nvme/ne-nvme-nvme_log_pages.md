# NVME_LOG_PAGES enumeration

## Description

Contains values that indicate the log pages that can be retrieved by the Get Log Page **NVME_ADMIN_COMMAND_GET_LOG_PAGE** Admin Command.

## Constants

### `NVME_LOG_PAGE_ERROR_INFO`

The Error Information log page that contains extended error information for a command that completed with an error or reported an error that is not specific to a particular command.

The information contained in the Error Information log page is defined in the [NVME_ERROR_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_error_info_log) structure.

### `NVME_LOG_PAGE_HEALTH_INFO`

The SMART / Health Information log page that contains SMART and general health information.

The information contained in the SMART/Health Information log page is defined in the [NVME_HEALTH_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_health_info_log) structure.

### `NVME_LOG_PAGE_FIRMWARE_SLOT_INFO`

The Firmware Slot Information log page that describes the firmware revision stored in each supported firmware slot.

The information contained in the Firmware Slot Information log page is defined in the [FIRMWARE_SLOT_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_firmware_slot_info_log) structure.

### `NVME_LOG_PAGE_CHANGED_NAMESPACE_LIST`

The Changed Namespace List log page that describes namespaces in the controller that have changed [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) information since the last time the log page was read.

The information contained in the Changed Namespace List log page is defined in the [CHANGED_NAMESPACE_LIST_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_changed_namespace_list_log) structure.

### `NVME_LOG_PAGE_COMMAND_EFFECTS`

The Commands Supported and Effects log page that describes the commands that the controller supports and the effects of those commands on the state of the NVM subsystem.

The information contained in the Commands Supported and Effects log page is defined in the [NVME_COMMAND_EFFECTS_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_log) structure.

### `NVME_LOG_PAGE_DEVICE_SELF_TEST`

The Device Self-Test log page that describes the status, completion percentage, and results of a device self-test.

The information contained in the Device Self Test log page is defined in the [NVME_DEVICE_SELF_TEST_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_device_self_test_log) structure.

### `NVME_LOG_PAGE_TELEMETRY_HOST_INITIATED`

The Telemetry Host-Initiated log page that describes telemetry data from the host.

The information contained in the Telemetry Host-Initiated log page is defined in the [NVME_TELEMETRY_HOST_INITIATED_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_device_self_test_log) structure.

### `NVME_LOG_PAGE_TELEMETRY_CTLR_INITIATED`

The Telemetry Controller-Initiated log page that describes telemetry data from the controller.

### `NVME_LOG_PAGE_RESERVATION_NOTIFICATION`

The Reservation Notification log page that is created whenever an unmasked reservation notification occurs on any namespace that may be accessed by the controller.

The information contained in the Reservation Notification log page is defined in the [NVME_RESERVATION_NOTIFICATION_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_reservation_notification_log) structure.

### `NVME_LOG_PAGE_ENDURANCE_GROUP_INFORMATION`

The Endurance Group Information log page that contains information about the amount of data being read from and written to an Endurance Group.

The information contained in the Endurance Group Information log page is defined in the [NVME_ENDURANCE_GROUP_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_endurance_group_log) structure.

### `NVME_LOG_PAGE_SANITIZE_STATUS`

The Sanitize Status log page that is created whenever an unmasked reservation notification occurs on any namespace that may be accessed by the controller.

## Remarks

## See also

[NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page)
[NVME_CDW10_GET_LOG_PAGE_V13](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13)