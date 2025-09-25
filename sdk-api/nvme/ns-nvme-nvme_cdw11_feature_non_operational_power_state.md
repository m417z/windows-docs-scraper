# NVME_CDW11_FEATURE_NON_OPERATIONAL_POWER_STATE structure

## Description

Contains parameters for the Non-Operational Power State Feature that indicates whether permissive mode is enabled for a non-operational power state.

A power state may be a non-operational power state, as indicated by the **NOPS** field of the [NVME_POWER_STATE_DESC](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_power_state_desc) structure that defines the Power State Descriptors in the **PDS** field of the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data). In a non-operational power state, memory-mapped I/O (MMIO) accesses, configuration register accesses and Admin Queue commands are serviced. No I/O commands are processed by the controller while in a non-operational power state.

When in a non-operational power state, regardless of whether [autonomous power state transitions](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_auto_power_state_transition) are enabled, the controller will autonomously transition back to the last operational power state when an [I/O Submission Queue Tail Doorbell](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_submission_queue_tail_doorbell) is written.

Servicing a memory-mapped I/O (MMIO) or configuration register access may cause the controller power to exceed that advertised by the non-operational power state while the access is being serviced, however, the controller will logically remain in the non-operational power state. Processing a command submitted to the Admin Submission Queue may also cause the controller power to exceed that advertised by the non-operational power state while the command is processed, however, the controller will logically remain in the current power state unless there is an explicit power state transition requested by a Set Features command with the [Power Management](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_power_management) feature identifier. When servicing a register access or an Admin command, the controller should not exceed the maximum power advertised for the last operational power state.

The values from this structure are used in the **NonOperationalPowerState** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NOPPME`

Specifies whether permissive mode is enabled for a non-operational power state.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [Power Management](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_power_management)
- [NVME_POWER_STATE_DESC](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_power_state_desc)
- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)