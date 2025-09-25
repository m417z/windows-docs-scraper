# CopyContext function

## Description

Copies a source context structure (including any XState) onto an initialized destination context
structure.

## Parameters

### `Destination` [in, out]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that receives the
context copied from the *Source*. The
**CONTEXT** structure should be initialized by calling
[InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext) before calling this
function.

### `ContextFlags` [in]

Flags specifying the pieces of the *Source*
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that will be copied into the
destination. This must be a subset of the *ContextFlags* specified when calling
[InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext) on the
*Destination* **CONTEXT**.

### `Source` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure from which to copy
processor context data.

## Return value

This function returns **TRUE** if the context was copied successfully, otherwise
**FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function copies data from the *Source*
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) over the corresponding data in the
*Destination* **CONTEXT**, including
extended context if any is present. The *Destination*
**CONTEXT** must have been initialized with
[InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext) to ensure proper alignment and
initialization. If any data is present in the *Destination*
**CONTEXT** and the corresponding flag is not set in the
*Source* **CONTEXT** or in the
*ContextFlags* parameter, the data remains valid in the
*Destination*.

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

[InitializeContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializecontext)

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)