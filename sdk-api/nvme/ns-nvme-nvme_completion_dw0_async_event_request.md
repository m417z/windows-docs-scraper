# NVME_COMPLETION_DW0_ASYNC_EVENT_REQUEST structure

## Description

Contains information about an asynchronous event that is posted to the Admin Completion Queue in DWord 0 of a Completion Queue Entry. Asynchronous events are used to notify the host software of status, error, and health information.

This structure is used in the **DW0** field of the [NVME_COMPLETION_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry).

## Members

### `AsyncEventType`

An [NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types) value that indicates the type of the asynchronous event.

More specific information about the event is provided in the Asynchronous Event Information (**AsyncEventInfo**) field.

### `Reserved0`

### `AsyncEventInfo`

Contains detailed information regarding the asynchronous event.

Depending on the value of **AsyncEventType**, this field will contain one of the following values:

- [NVME_ASYNC_EVENT_ERROR_STATUS_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_error_status_codes)
- [NVME_ASYNC_EVENT_HEALTH_STATUS_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_health_status_codes)
- [NVME_ASYNC_EVENT_NOTICE_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_notice_codes)
- [NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types)

### `LogPage`

Indicates the log page associated with the asynchronous event. This log page must be read by the host to clear the event.

### `Reserved1`

## Remarks

## See also

- [NVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_async_event_config)