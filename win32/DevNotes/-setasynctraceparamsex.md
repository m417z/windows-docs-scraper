# SetAsyncTraceParamsEx function

Finishes setting up a trace buffer with optional fields for **sprintf**-style traces.

## Parameters

*pszModule*

The name of the module that is associated with the trace.

*pszFile*

The name of the source file that contains the exception.

*lLine*

The line number of the exception in the source file.

*pszFunction*

The function name of the exception.

*dwTraceMask*

A trace flag constant that represents one of the available trace types. This parameter can be any of the following values.

**FATAL\_TRACE\_MASK** (0x00000001)

**ERROR\_TRACE\_MASK** (0x00000002)

**DEBUG\_TRACE\_MASK** (0x00000004)

**STATE\_TRACE\_MASK** (0x00000008)

**FUNCT\_TRACE\_MASK** (0x00000010)

**MESSAGE\_TRACE\_MASK** (0x00000020)

**ALL\_TRACE\_MASK** (0xFFFFFFFF)

## Return value

This function returns 1 if the function succeeds; otherwise, it returns 0.

## Remarks

Exstrace.dll is an optional component that installs with the Simple Mail Transfer Protocol (SMTP) and the Network News Transfer Protocol (NNTP).

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Exstrace.dll |

