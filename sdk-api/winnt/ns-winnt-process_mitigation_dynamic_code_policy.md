# PROCESS_MITIGATION_DYNAMIC_CODE_POLICY structure

## Description

Contains process mitigation policy settings for restricting dynamic code generation and modification.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ProhibitDynamicCode`

Set (0x1) to prevent the process from generating dynamic code or modifying existing executable code; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AllowThreadOptOut`

Set (0x1) to allow threads to opt out of the restrictions on dynamic code generation by calling the [SetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation) function with the *ThreadInformation* parameter set to **ThreadDynamicCodePolicy**; otherwise leave unset (0x0). You should not use the **AllowThreadOptOut** and **ThreadDynamicCodePolicy** settings together to provide strong security. These settings are only intended to enable applications to adapt their code more easily for full dynamic code restrictions.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AllowRemoteDowngrade`

Set (0x1) to allow non-AppContainer processes to modify all of the dynamic code settings for the calling process, including relaxing dynamic code restrictions after they have been set.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditProhibitDynamicCode`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved for system use.

## See also

[GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy)

[SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)