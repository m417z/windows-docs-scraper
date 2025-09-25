# NVME_RESERVATION_NOTIFICATION_TYPES enumeration

## Description

Contains values that indicate the type of reservation notification in a Reservation Notification log page. A Reservation Notification log page is created whenever an unmasked reservation notification occurs on a namespace associated with the controller.

Reservation notifications may be masked from generating a reservation log page on a per reservation notification type and per namespace ID basis through the [Reservation Notification Mask (NVME_FEATURE_NVM_RESERVATION_NOTIFICATION_MASK)](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features) feature.

A host may use the Asynchronous Event Request command to be notified of the presence of one or more available Reservation Notification log pages.

## Constants

### `NVME_RESERVATION_NOTIFICATION_TYPE_EMPTY_LOG_PAGE`

The log page is empty. The Get Log Page command was processed when no unread Reservation Notification log pages were available. All the fields of an empty log page have a value of zero.

### `NVME_RESERVATION_NOTIFICATION_TYPE_REGISTRATION_PREEMPTED`

The registration is preempted.

### `NVME_RESERVATION_NOTIFICATION_TYPE_REGISTRATION_RELEASED`

The reservation is released.

### `NVME_RESERVATION_NOTIFICATION_TYPE_RESERVATION_PREEPMPTED`

The reservation is preempted.

## Remarks

Use this enumeration to specify values in the **NVME_LOG_PAGE_RESERVATION_NOTIFICATION** field of the [NVME_LOG_PAGES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_log_pages) enumeration that is used in the [NVME_ADMIN_COMMAND_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) Admin command.

## See also