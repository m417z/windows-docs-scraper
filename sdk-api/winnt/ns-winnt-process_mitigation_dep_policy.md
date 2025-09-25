# PROCESS_MITIGATION_DEP_POLICY structure

## Description

Contains process mitigation policy settings for data execution prevention (DEP). The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Enable`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisableAtlThunkEmulation`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

### `Permanent`

DEP is permanently enabled and cannot be disabled if this field is set to TRUE.

#### - DisableAtlThunkEmulation : 1

ATL thunk emulation is disabled for the process if this flag is set.

#### - Enable : 1

DEP is enabled for the process if this flag is set.

#### - ReservedFlags : 30

This member is reserved for system use.