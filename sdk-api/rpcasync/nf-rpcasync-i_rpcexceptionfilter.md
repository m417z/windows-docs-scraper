## Description

Determines whether an exception is fatal or non-fatal

## Parameters

### `ExceptionCode`

Value of an exception. Any of the following exception values will return EXCEPTION_CONTINUE_SEARCH:

- STATUS_ACCESS_VIOLATION
- STATUS_POSSIBLE_DEADLOCK
- STATUS_INSTRUCTION_MISALIGNMENT
- STATUS_DATATYPE_MISALIGNMENT
- STATUS_PRIVILEGED_INSTRUCTION
- STATUS_ILLEGAL_INSTRUCTION
- STATUS_BREAKPOINT
- STATUS_STACK_OVERFLOW
- STATUS_HANDLE_NOT_CLOSABLE
- STATUS_IN_PAGE_ERROR
- STATUS_ASSERTION_FAILURE
- STATUS_STACK_BUFFER_OVERRUN
- STATUS_GUARD_PAGE_VIOLATION
- STATUS_REG_NAT_CONSUMPTION

## Return value

A value that specifies whether the exception was fatal or non-fatal.

| Return code | Description
|-------------|------------|
| EXCEPTION_CONTINUE_SEARCH | The exception is fatal and must be handled. |
| EXCEPTION_EXECUTE_HANDLER | The exception is not fatal. |

## Remarks

## See also