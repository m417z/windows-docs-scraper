# GetXStateFeaturesMask function

## Description

Returns the mask of XState features set within a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) structure.

## Parameters

### `Context` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) structure that has been
initialized with [InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext).

### `FeatureMask` [out]

A pointer to a variable that receives the mask of XState features which are present in the specified
**CONTEXT** structure.

## Return value

This function returns **TRUE** if successful, otherwise
**FALSE**.

## Remarks

The **GetXStateFeaturesMask** function returns
the mask of valid features in the specified context. If a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) is to be passed to
[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext) or
[Wow64GetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64getthreadcontext.md), the application must
call [SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask) to set which
features are to be retrieved.
**GetXStateFeaturesMask** should then be called on
the **CONTEXT** returned by
**GetThreadContext** or
**Wow64GetThreadContext** to determine which
feature areas contain valid data. If a particular feature bit is not set, the corresponding state is in a
processor-specific **INITIALIZED** state and the contents of the feature area retrieved by
[LocateXStateFeature](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locatexstatefeature) are undefined.

The definition of XState features are processor vendor specific. Please refer to the relevant processor
reference manuals for additional information on a particular feature.

**Note** The value returned by
**GetXStateFeaturesMask** on a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) after a context operation will always be a subset
of the mask specified in a call to
[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask) prior to the context
operation.

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

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context)

[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)

[Wow64GetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64getthreadcontext.md)