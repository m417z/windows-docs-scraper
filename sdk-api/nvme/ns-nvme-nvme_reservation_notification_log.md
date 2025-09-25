# NVME_RESERVATION_NOTIFICATION_LOG structure

## Description

Contains fields that specify the information in a Reservation Notification Log page.

A Reservation Notification log page is created whenever an unmasked reservation notification occurs on any namespace that may be accessed by the controller. The [Get Log Page](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page) command returns a data buffer containing a log page corresponding to a single reservation notification. This log page is global to the controller.

## Members

### `LogPageCount`

A 64-bit incrementing Reservation Notification log page count, indicating a unique identifier for this notification.

The count starts at `0h` following a controller reset, is incremented with each unique log entry, and rolls over to zero when the maximum count is reached and a log page is created. A value of `0h` indicates an empty log entry.

### `LogPageType`

A [NVME_RESERVATION_NOTIFICATION_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_reservation_notification_types) value that indicates the Reservation Notification type described by this log page.

### `AvailableLogPageCount`

Indicates the number of additional available Reservation Notification log pages (for example, the number of unread log pages not counting this one).

If there are more than 255 additional available log pages, a value of `255` is returned. A value of zero indicates that there are no additional available log pages.

### `Reserved0`

A reserved field.

### `NameSpaceId`

Indicates the namespace ID of the namespace associated with the Reservation Notification described by this log page.

### `Reserved1`

A reserved field.

## Remarks

## See also

- [NVME_RESERVATION_NOTIFICATION_TYPES enumeration](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_reservation_notification_types)
- [Get Log Page](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page)