## Description

Contains process mitigation policy settings for user-mode Hardware-enforced Stack Protection (HSP). The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditBlockNonCetBinaries`

If TRUE, binary loads that would have been blocked are instead allowed and diagnostic events are logged in the Event Log.
When this field is TRUE, BlockNonCetBinaries must be TRUE and BlockNonCetBinariesNonEhcont may be TRUE, depending on which types of binaries are currently being blocked from being loaded into the process.
This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditSetContextIpValidation`

If TRUE, Instruction Pointers that would have caused the validation to fail are instead allowed and diagnostic events are logged in the Event Log.
When this field is TRUE, SetContextIpValidation must be TRUE and SetContextIpValidationRelaxedMode may be TRUE, depending on which mode the Instruction Pointer validation is currently operating in.
This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditUserShadowStack`

If TRUE, shadow stack violations that would have been fatal are instead treated as not fatal and diagnostic events are logged in the Event Log.
When this field is TRUE, EnableUserShadowStack must be TRUE and EnableUserShadowStackStrictMode may be TRUE, depending on whether compatibility mode is being audited or strict mode is being audited.
This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BlockNonCetBinaries`

If TRUE, binaries that are not compiled with CETCOMPAT are blocked from being loaded into the process.
This policy can be enabled after a process has started by calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It cannot be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BlockNonCetBinariesNonEhcont`

If TRUE, binaries that are not compiled with CETCOMPAT or do not contain exception handling continuation metadata ([/guard:ehcont](https://learn.microsoft.com/cpp/build/reference/guard-enable-eh-continuation-metadata)) are blocked from being loaded into the process.
When this field is TRUE, BlockNonCetBinaries must be TRUE.
This policy can be enabled after a process has started by calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It cannot be disabled or downgraded once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.CetDynamicApisOutOfProcOnly`

If TRUE, certain HSP APIs used to specify security properties of dynamic code can only be called from outside of the process for security purposes.
These APIs are [SetProcessDynamicEHContinuationTargets](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessdynamicehcontinuationtargets) and [SetProcessDynamicEnforcedCetCompatibleRanges](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessdynamicenforcedcetcompatibleranges).
This policy can be enabled after a process has started by calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It cannot be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableUserShadowStack`

If TRUE, user-mode Hardware-enforced Stack Protection is enabled for the process in compatibility mode.
This means that the CPU verifies function return addresses at runtime by employing a shadow stack mechanism, if supported by the hardware.
In compatibility mode, only shadow stack violations occurring in modules that are considered compatible with shadow stacks (CETCOMPAT) are fatal.
For a module to be considered CETCOMPAT, it needs to be either compiled with [CETCOMPAT](https://learn.microsoft.com/cpp/build/reference/cetcompat) for binaries, or marked using
[SetProcessDynamicEnforcedCetCompatibleRanges](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessdynamicenforcedcetcompatibleranges) for dynamic code.
This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableUserShadowStackStrictMode`

If TRUE, user-mode Hardware-enforced Stack Protection is enabled for the process in strict mode. All shadow stack violations are fatal.
When this field is TRUE, EnableUserShadowStack must be TRUE.
If HSP is enabled in compatibility mode, it can be upgraded to strict mode at runtime by setting this field to TRUE and calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).
HSP cannot be downgraded or disabled via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).
If HSP is disabled, it cannot be enabled via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.SetContextIpValidation`

If TRUE, when calling APIs that modify the execution context of a thread such as [SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) and [RtlRestoreContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-rtlrestorecontext), validation is performed on the Instruction Pointer specified in the new execution context.
This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.SetContextIpValidationRelaxedMode`

If TRUE, the process's Instruction Pointer validation is downgraded to relaxed mode, which allows all Instruction Pointers that are in dynamic code or in binaries that do not contain [exception handling continuation metadata](https://learn.microsoft.com/cpp/build/reference/guard-enable-eh-continuation-metadata).
When this field is TRUE, SetContextIpValidation must be TRUE.
The process can be upgraded from relaxed mode to normal mode at runtime by setting this field to FALSE and calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

This member is reserved for system use.

## Remarks

## See also

[CETCOMPAT](https://learn.microsoft.com/cpp/build/reference/cetcompat)

[GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy)

[SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)