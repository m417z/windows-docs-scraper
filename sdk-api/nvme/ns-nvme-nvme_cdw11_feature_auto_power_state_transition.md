# NVME_CDW11_FEATURE_AUTO_POWER_STATE_TRANSITION structure

## Description

Contains parameters for the Autonomous Power State Transition Feature that configures the settings for autonomous power state transitions.

The values from this structure are used in the **AutoPowerStateTransition** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.APSTE`

Specifies whether the autonomous power state transition is enabled.

When the value of this field is set to `1`, autonomous power state transitions are enabled. When the value of this field is cleared to `0`, autonomous power state transitions are disabled. This field is cleared to `0` by default.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_AUTO_POWER_STATE_TRANSITION_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_auto_power_state_transition_entry)
- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)