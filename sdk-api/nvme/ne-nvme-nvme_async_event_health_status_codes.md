# NVME_ASYNC_EVENT_HEALTH_STATUS_CODES enumeration

## Description

Contains values that indicate a SMART/Health Status event type.

## Constants

### `NVME_ASYNC_HEALTH_NVM_SUBSYSTEM_RELIABILITY`

NVM subsystem reliability has been compromised. This may be due to significant media errors, an internal error, the media being placed in read only mode, or a volatile memory backup device failing.

### `NVME_ASYNC_HEALTH_TEMPERATURE_THRESHOLD`

A temperature is above an over-temperature threshold or below an under-temperature threshold.

### `NVME_ASYNC_HEALTH_SPARE_BELOW_THRESHOLD`

The available spare space has fallen below the threshold.

## Remarks

Use this enumeration to specify values in the **NVME_ASYNC_EVENT_TYPE_HEALTH_STATUS** field of the [NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types) enumeration that is used in the Async Event Request Admin command.

## See also

[NVME_ASYNC_EVENT_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_types)
[NVME_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features)
[NVME_ADMIN_COMMANDS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands)