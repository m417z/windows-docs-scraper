# NVME_CSTS_SHST_SHUTDOWN_STATUS enumeration

## Description

Contains values that indicate the status of shutdown processing that is initiated by the host setting the **SHN** field in the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) structure.

## Constants

### `NVME_CSTS_SHST_NO_SHUTDOWN`

Normal operation (no shutdown has been requested).

### `NVME_CSTS_SHST_SHUTDOWN_IN_PROCESS`

Shutdown processing is occurring.

### `NVME_CSTS_SHST_SHUTDOWN_COMPLETED`

Shutdown processing is complete.

## Remarks

To start executing commands on the controller after a shutdown operation, (when the **SHST** field of the [NVME_CONTROLLER_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_status) structure is set to `10b`, a Controller Reset (setting the **EN** field in [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) to `0`) is required. If the host software submits commands to the controller without issuing a reset, the behavior is undefined.

## See also

[NVME_CONTROLLER_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_status)
[NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration)