# EXCEPTION_DEBUG_INFO structure

## Description

Contains exception information that can be used by a debugger.

## Members

### `ExceptionRecord`

An
[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure with information specific to the exception. This includes the exception code, flags, address, a pointer to a related exception, extra parameters, and so on.

### `dwFirstChance`

A value that indicates whether the debugger has previously encountered the exception specified by the **ExceptionRecord** member. If the **dwFirstChance** member is nonzero, this is the first time the debugger has encountered the exception. Debuggers typically handle breakpoint and single-step exceptions when they are first encountered. If this member is zero, the debugger has previously encountered the exception. This occurs only if, during the search for structured exception handlers, either no handler was found or the exception was continued.

## See also

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)