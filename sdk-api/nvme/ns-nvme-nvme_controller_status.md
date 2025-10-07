# NVME_CONTROLLER_STATUS structure

## Description

Contains values that indicate controller status.

This structure is used in the **CSTS** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.RDY`

Indicates whether the controller is ready to accept [Submission Queue Tail doorbell](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_submission_queue_tail_doorbell) writes.

When this value is set to `1`, the controller is ready to accept Submission Queue Tail doorbell writes after the **EN** field in the [Controller configuration](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) is set to `1`.

This value is cleared to `0` when **EN** is cleared to `0`. Commands cannot be submitted to the controller until this field is set to `1` after **EN** is set to `1`. Failure to follow this requirement produces undefined results.

Host software must wait at least as long as the Timeout **TO** value in [Controller Capabilities](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) for this field to be set to `1` after **EN** is set to `1` from a previous value of `0`.

### `DUMMYSTRUCTNAME.CFS`

Indicates whether a fatal controller error has occurred.

When this value is set to `1`, a fatal controller error occurred that could not be communicated in the appropriate Completion Queue.
When this value is cleared to `0`, a fatal controller error has not occurred.

The reset value of this field is `1` when a fatal controller error is detected during controller initialization.

### `DUMMYSTRUCTNAME.SHST`

A [NVME_CSTS_SHST_SHUTDOWN_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_csts_shst_shutdown_status) value that indicates the status of shutdown processing. Shutdown processing is initiated by the host setting the **SHN** field of the [Controller configuration](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration).

To start executing commands on the controller after a shutdown operation (indicated when this value is set to **NVME_CSTS_SHST_SHUTDOWN_COMPLETED**), a Controller Reset, setting the **EN** field of the [Controller configuration](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) to `0`, is required. If the host software submits commands to the controller without issuing a reset, the behavior is undefined.

### `DUMMYSTRUCTNAME.NSSRO`

Indicates that the last NVM Subsystem Reset occurred while power was applied to the NVM subsystem.

When this value is set to `1`, the last occurrence of an NVM Subsystem Reset occurred while power was applied to the NVM subsystem.

The initial value of this field is `0` following an NVM Subsystem Reset due to application of power to the NVM subsystem. This field is only valid if the controller supports the NVM Subsystem Reset feature, indicated by the **NSSRS** field of [Controller Capabilities](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) being set to `1`.

The reset value of this field is `0` if an NVM Subsystem Reset causes activation of a new firmware image.

### `DUMMYSTRUCTNAME.PP`

Indicates whether the controller is processing commands.

When this value is cleared to `0`, the controller is processing commands normally. When this value is set to `1`, the controller has temporarily stopped processing commands in order to handle an event, such as firmware activation.

This field is only valid when the **EN** field of the [Controller configuration](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) is set to `1`.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers)