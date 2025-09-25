# PROCESS_MITIGATION_ASLR_POLICY structure

## Description

Contains process mitigation policy settings for Address Space Randomization Layout (ASLR). The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableBottomUpRandomization`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableForceRelocateImages`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableHighEntropy`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisallowStrippedImages`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

#### - DisallowStrippedImages : 1

Images that have not been built with /DYNAMICBASE and do not have relocation information will fail to load if this flag and **EnableForceRelocateImages** are set.

#### - EnableBottomUpRandomization : 1

Thread stacks and other bottom-up allocations are subject to randomization by ASLR if this flag is set. This flag is read-only and cannot be modified after a process has been created.

#### - EnableForceRelocateImages : 1

Images that have not been built with /DYNAMICBASE are forcibly relocated on load if this flag is set.

#### - EnableHighEntropy : 1

Bottom-up allocations are subject to higher degrees of entropy when randomized by ASLR if this flag is set. This flag only applies to 64-bit processes and is read-only.

#### - ReservedFlags : 28

This member is reserved for system use.