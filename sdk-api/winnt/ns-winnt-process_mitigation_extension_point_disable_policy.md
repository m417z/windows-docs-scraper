# PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY structure

## Description

Contains process mitigation policy settings for legacy extension point DLLs. The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisableExtensionPoints`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

#### - DisableExtensionPoints : 1

Prevents legacy extension point DLLs from being loaded into the process.

#### - ReservedFlags : 31

This member is reserved for system use.