# MACHINE_PROCESSOR_POWER_POLICY structure

## Description

Contains processor power policy settings that apply while the system is running on AC power or battery power.

## Members

### `Revision`

The current structure revision level. Set this value by calling [ReadProcessorPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readprocessorpwrscheme) before using a **MACHINE_PROCESSOR_POWER_POLICY** structure to set power policy.

### `ProcessorPolicyAc`

A
[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy) structure that defines the processor power policy settings used while the computer is running on AC power.

### `ProcessorPolicyDc`

A
[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy) structure that defines the processor power policy settings used while the computer is running on battery power.

## See also

[PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy)

[ReadProcessorPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readprocessorpwrscheme)

[WriteProcessorPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writeprocessorpwrscheme)