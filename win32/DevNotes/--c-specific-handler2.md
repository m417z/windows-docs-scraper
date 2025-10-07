# \_\_C\_specific\_handler function

Called by the compiler to implement structured exception handling extensions.

The relative address of the language specific handler is present in the UNWIND\_INFO whenever flags UNW\_FLAG\_EHANDLER or UNW\_FLAG\_UHANDLER are set. The language specific handler is called as part of the search for an exception handler or as part of an unwind. For more information see [Language Specific Handler](https://learn.microsoft.com/cpp/build/exception-handling-x64#language-specific-handler).

## Parameters

*ExceptionRecord* \[in\]

Supplies a pointer to an exception record, which has the standard Win64 definition.

*EstablisherFrame* \[in\]

The address of the base of the fixed stack allocation for this function.

*ContextRecord* \[in, out\]

Points to the exception context at the time the exception was raised (in the exception handler case) or the current "unwind" context (in the termination handler case).

*DispatcherContext* \[in, out\]

Points to the dispatcher context for this function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | Wdm.h |
| Library<br> | NtosKrnl.lib |
| DLL<br> | Ntoskrnl.exe |

