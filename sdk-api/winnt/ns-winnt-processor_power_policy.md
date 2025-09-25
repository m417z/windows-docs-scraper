# PROCESSOR_POWER_POLICY structure

## Description

Contains information about processor performance control and C-states.

## Members

### `Revision`

The current structure revision level. Set this value by calling [ReadProcessorPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readprocessorpwrscheme) before using a **PROCESSOR_POWER_POLICY** structure to set power policy.

### `DynamicThrottle`

The current processor performance state policy. This member must be one of the values described in
[Processor Performance Control Policy Constants](https://learn.microsoft.com/windows/desktop/Power/processor-performance-control-policy-constants).

### `Spare`

Reserved; set to zero.

### `DisableCStates`

Reserved; set to zero.

### `Reserved`

Reserved; set to zero.

### `PolicyCount`

The number of elements in the **Policy** array.

### `Policy`

An array of
[PROCESSOR_POWER_POLICY_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy_info) structures that defines values used to apply processor C-state policy settings. Policy[0] corresponds to ACPI C-state C1, Policy[1] corresponds to C2, and Policy[2] corresponds to C3. The **AllowPromotion** member determines whether the processor can be promoted to the state. For example, if Policy[0].AllowPromotion is 0, the computer cannot transition from C0 to C1.

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[PROCESSOR_POWER_POLICY_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_power_policy_info)