# NVME_ASYNC_EVENT_IO_COMMAND_SET_STATUS_CODES enumeration

## Description

Contains values that indicate an I/O Command Set event type.

## Constants

### `NVME_ASYNC_IO_CMD_SET_RESERVATION_LOG_PAGE_AVAILABLE`

One or more [Reservation Notification log](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_reservation_notification_log) pages are available.

### `NVME_ASYNC_IO_CMD_SANITIZE_OPERATION_COMPLETED`

A sanitize operation has completed without unexpected deallocation of all LBAs.

### `NVME_ASYNC_IO_CMD_SANITIZE_OPERATION_COMPLETED_WITH_UNEXPECTED_DEALLOCATION`

A sanitize operation has completed with unexpected deallocation of all LBAs and status is available in the Sanitize Status log page.

## Remarks

Values from this enumeration are used in the **NVME_ASYNC_EVENT_TYPE_IO_COMMAND_SET_STATUS** field of the [NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types) enumeration.

## See also

[NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types)
[NVME_RESERVATION_NOTIFICATION_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_reservation_notification_log)