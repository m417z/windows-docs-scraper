# NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMITS enumeration

## Description

Contains values that indicate the command submission and execution recommendations for the associated command.

## Constants

### `NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_NONE`

No command submission or execution restriction.

### `NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_SINGLE_PER_NAMESPACE`

The command may be submitted when there is no other outstanding command to the same namespace and another command should not be submitted to the same namespace until this command is complete.

### `NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_SINGLE_PER_CONTROLLER`

The command may be submitted when there is no other outstanding command to any namespace and another command should not be submitted to any namespace until this command is complete.

## Remarks

Use the values from this enumeration in the Command Submission and Execution (**CSE**) field of the [NVME_COMMAND_EFFECTS_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_data) structure.

## See also

[NVME_COMMAND_EFFECTS_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_data)