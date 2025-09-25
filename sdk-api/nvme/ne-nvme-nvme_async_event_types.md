# NVME_ASYNC_EVENT_TYPES enumeration

## Description

Contains values that indicate an asynchronous event type.

## Constants

### `NVME_ASYNC_EVENT_TYPE_ERROR_STATUS`

A general error that is not associated with a specific command. The status of this event is one of the values specified in the **NVME_ASYNC_EVENT_ERROR_STATUS_CODES** enumeration.

### `NVME_ASYNC_EVENT_TYPE_HEALTH_STATUS`

A SMART or Health status event. The status of this event is one of the values specified in the **NVME_ASYNC_EVENT_HEALTH_STATUS_CODES** enumeration.

### `NVME_ASYNC_EVENT_TYPE_NOTICE`

A Notice event. The status of this event is one of the values specified in the **NVME_ASYNC_EVENT_NOTICE_CODES** enumeration.

### `NVME_ASYNC_EVENT_TYPE_IO_COMMAND_SET_STATUS`

An I/O Command Set event. The status of this event is one of the values specified in the **NVME_ASYNC_EVENT_IO_COMMAND_SET_STATUS_CODES** enumeration.

### `NVME_ASYNC_EVENT_TYPE_VENDOR_SPECIFIC`

A vendor specific event. The status of this event is one of the values specified in the **NVME_ASYNC_EVENT_TYPE_VENDOR_SPECIFIC_CODES** enumeration.

## Remarks

Use the Event type information values from this enumeration in [Dword 0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) of the Completion Queue entry for an Asynchronous Event Request command.

## See also