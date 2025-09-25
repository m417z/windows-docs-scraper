# SECPKG_DLL_FUNCTIONS structure

## Description

The **SECPKG_DLL_FUNCTIONS** structure contains pointers to the LSA functions that a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) can call while executing in-process with a client/server application. The [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) provides this structure during user-mode initialization using each security package's
[SpInstanceInit](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinstanceinitfn) function.

## Members

### `AllocateHeap`

Pointer to the [AllocateHeap](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374721(v=vs.85)) function.

### `FreeHeap`

Pointer to the [FreeHeap](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa375418(v=vs.85)) function.

### `RegisterCallback`

Pointer to the [RegisterCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa379372(v=vs.85)) function.

### `LocatePackageById`