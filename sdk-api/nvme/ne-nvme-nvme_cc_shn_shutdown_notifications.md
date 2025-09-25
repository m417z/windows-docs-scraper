# NVME_CC_SHN_SHUTDOWN_NOTIFICATIONS enumeration

## Description

Contains values that indicate a Controller Configuration (CC) shutdown notification.

## Constants

### `NVME_CC_SHN_NO_NOTIFICATION`

No notification and no effect.

### `NVME_CC_SHN_NORMAL_SHUTDOWN`

Normal shutdown notification.

### `NVME_CC_SHN_ABRUPT_SHUTDOWN`

Abrupt shutdown notification.

## Remarks

Use the CC shutdown notification values from this enumeration in the **SHN** field (offset 14h) of the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) structure.

## See also

[NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration)