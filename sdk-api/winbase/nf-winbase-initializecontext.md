# InitializeContext function

## Description

Initializes a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure inside a buffer
with the necessary size and alignment.

## Parameters

### `Buffer` [out, optional]

A pointer to a buffer within which to initialize a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure. This parameter can be
**NULL** to determine the buffer size required to hold a context record with the
specified *ContextFlags*.

### `ContextFlags` [in]

A value indicating which portions of the *Context* structure should be initialized.
This parameter influences the size of the initialized *Context* structure.

**Note** **CONTEXT_XSTATE** is not part of **CONTEXT_FULL** or
**CONTEXT_ALL**. It must be specified separately if an XState context is desired.

### `Context` [out, optional]

A pointer to a variable which receives the address of the initialized
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure within the
*Buffer*.

**Note** Due to alignment requirements of [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structures,
the value returned in *Context* may not be at the beginning of the supplied
buffer.

### `ContextLength` [in, out]

On input, specifies the length of the buffer pointed to by *Buffer*, in bytes. If
the buffer is not large enough to contain the specified portions of the
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context), the function fails,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INSUFFICIENT_BUFFER**, and *ContextLength* is set to the
required size of the buffer. If the function fails with an error other than
**ERROR_INSUFFICIENT_BUFFER**, the contents of
*ContextLength* are undefined.

## Return value

This function returns **TRUE** if successful, otherwise
**FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

*InitializeContext* can be used to initialize a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure within a buffer with the required size and
alignment characteristics. This routine is required if the **CONTEXT_XSTATE** *ContextFlag* is specified since the required context size and alignment may change
depending on which processor features are enabled on the system.

First, call this function with the
*ContextFlags* parameter set to the maximum number of features you will be using and the
*Buffer* parameter to **NULL**. The function returns the required
buffer size in bytes in the *ContextLength* parameter. Allocate enough space for the data
in the *Buffer* and call the function again to initialize the
*Context*. Upon successful completion of this routine, the
*ContextFlags* member of the *Context* structure is initialized,
but the remaining contents of the structure are undefined. Some bits specified in the
*ContextFlags* parameter may not be set in
*Context*->*ContextFlags* if they are not supported by the
system. Applications may subsequently remove, but must never add, bits from the
*ContextFlags* member of
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context).

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

[CopyContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copycontext)

[Intel AVX](https://learn.microsoft.com/windows/desktop/Debug/avx-support-portal)

[Working with XState Context](https://learn.microsoft.com/windows/desktop/Debug/working-with-xstate-context)