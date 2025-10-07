# AsyncStringTrace function

Finishes setting up a trace buffer with optional fields for **sprintf**-style traces.

## Parameters

*lParam*

A 32-bit trace parameter that is used for application-level filtering.

*szFormat*

A zero-terminated string that describes the format of the trace.

*marker*

A marker for **vsprintf** functions.

## Return value

This function returns the length of the trace statement, in bytes.

## Remarks

Exstrace.dll is an optional component that installs with the Simple Mail Transfer Protocol (SMTP) and the Network News Transfer Protocol (NNTP).

The **va\_list** data type is a standard type that is used to hold information needed by **va\_arg** and **va\_end** macros. For more information, see [Standard Types](https://learn.microsoft.com/cpp/c-runtime-library/standard-types).

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Exstrace.dll |

