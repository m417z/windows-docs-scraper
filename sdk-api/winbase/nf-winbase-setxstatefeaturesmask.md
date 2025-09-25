# SetXStateFeaturesMask function

## Description

Sets the mask of XState features set within a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure.

## Parameters

### `Context` [in, out]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that has been
initialized with [InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext).

### `FeatureMask` [in]

A mask of XState features to set in the specified
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure.

## Return value

This function returns **TRUE** if successful, otherwise
**FALSE**.

## Remarks

The **SetXStateFeaturesMask** function sets the
mask of valid features in the specified context. Before calling
[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext),
[Wow64GetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64getthreadcontext.md),
[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext), or
[Wow64SetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64setthreadcontext.md) the application must call
**SetXStateFeaturesMask** to specify which set of
features to retrieve or set. The system silently ignores any feature specified in the
*FeatureMask* which is not enabled on the processor.

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

[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)

[Wow64GetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64getthreadcontext.md)

[Wow64SetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64setthreadcontext.md)