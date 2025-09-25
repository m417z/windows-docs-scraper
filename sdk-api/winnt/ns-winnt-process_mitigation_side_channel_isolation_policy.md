## Description

This data structure provides the status of process policies that are related to the mitigation of side channels. This can include side channel attacks involving speculative execution and page combining.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.SmtBranchTargetIsolation`

If **TRUE** then, while this process is executing in user-mode, requests the application of hardware mitigations to prevent cross-SMT-thread branch target pollution.

If the hardware doesn't provide support for such a mitigation, or the mitigation has been disabled system-wide, then this policy has no effect.

To enable this policy after a process has started, you can call [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It can't be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.IsolateSecurityDomain`

If **TRUE**, isolates this process into a distinct security domain, even from other processes running as the same security context. That prevents branch target injection cross-process.

Page-combining is limited to processes within the same security domain. This flag effectively limits the process to only combining internally to the process itself, except for common pages and unless further restricted by the **DisablePageCombine** policy.

To enable this policy after a process has started, you can call [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It can't be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisablePageCombine`

If **TRUE**, disables all page-combining for this process, even internally to the process itself, except for common pages (pages of entirely 0s or entirely 1s).

To enable this policy after a process has started, you can call [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It can't be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.SpeculativeStoreBypassDisable`

If **TRUE** then, while this process is executing in user-mode, and in order to mitigate intra-process SSB, requests that hardware mitigations for Speculative Store Bypass (SSB) be enabled.

If the hardware doesn't provide support for such a mitigation, or the mitigation has been disabled system-wide, then this policy has no effect.

To enable this policy after a process has started, you can call [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It can't be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.RestrictCoreSharing`

If **TRUE**, the CPU scheduler prevents threads within this process from being scheduled to the same core as threads from another security domain.

This policy can't be enabled on systems where the scheduler is incapable of providing this guarantee. For example, this policy can't be enabled for processes in a virtual machine unless the hypervisor reports the absence of [non-architectural core sharing](https://learn.microsoft.com/windows-server/virtualization/hyper-v/manage/about-hyper-v-scheduler-type-selection#nononarchitecturalcoresharing-enlightenment-details).

To enable this policy after a process has started, you can call [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It can't be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

This member is reserved for system use.