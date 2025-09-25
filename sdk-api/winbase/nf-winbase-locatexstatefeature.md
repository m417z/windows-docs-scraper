# LocateXStateFeature function

## Description

Retrieves a pointer to the processor state for an XState feature within a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure.

The definition of XState feature bits are processor vendor specific. Please refer to the relevant processor
reference manuals for additional information on a particular feature.

## Parameters

### `Context` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure containing the state
to retrieve or set. This **CONTEXT** should have been
initialized with [InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext) with the
**CONTEXT_XSTATE** flag set in the *ContextFlags*
parameter.

### `FeatureId` [in]

The number of the feature to locate within the
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure.

### `Length` [out, optional]

A pointer to a variable which receives the length of the feature area in bytes. The contents of this
variable are undefined if this function returns **NULL**.

## Return value

If the specified feature is supported by the system and the specified
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure has been initialized with the
**CONTEXT_XSTATE** flag, this function returns a pointer to the feature area for the
specified feature. The contents and layout of this area is processor-specific.

If the **CONTEXT_XSTATE** flag is not set in the
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure or the
*FeatureID* is not supported by the system, the return value is
**NULL**. No additional error information is available.

## Remarks

The **LocateXStateFeature** function must be used
to find an individual XState feature within an extensible
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure. Features are not necessarily contiguous
in memory and applications should not assume the offset between two consecutive features will remain constant in
the future.

The *FeatureID* parameter of the function corresponds to a bit within the feature
mask. For example, *FeatureId* 2 corresponds to a *FeatureMask* of
4 in [SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask).
*FeatureID* values of 0 and 1 correspond to X87 FPU state and SSE state,
respectively.

If you are setting XState on a thread via the
[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) or
[Wow64SetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/)
APIs, you must also call
[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask) on the
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure with the mask value of the filled-in
feature to mark the feature as active.

**Windows 7 with SP1 and Windows Server 2008 R2 with SP1:** The [AVX API](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal) is first implemented on
Windows 7 with SP1 and Windows Server 2008 R2 with SP1 . Since there is no SDK for SP1, that means there are
no available headers and library files to work with. In this situation, a caller must declare the needed
functions from this documentation and get pointers to them using
[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) on
"Kernel32.dll", followed by calls to
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). See
[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context) for
details.

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)

[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)

[Wow64SetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/)