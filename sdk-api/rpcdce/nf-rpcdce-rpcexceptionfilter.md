# RpcExceptionFilter function

## Description

The **RpcExceptionFilter** function is a default exception filter that determines whether an exception is fatal or non-fatal. **RpcExceptionFilter** is recommended for structured exception handling for the most common exceptions as an alternative to custom filters with [RpcExcept](https://learn.microsoft.com/windows/desktop/api/rpc/nf-rpc-rpcexcept).

## Parameters

### `ExceptionCode` [in]

Value of an exception. Any of the following exception values will return **EXCEPTION_CONTINUE_SEARCH**:

#### STATUS_ACCESS_VIOLATION

#### STATUS_POSSIBLE_DEADLOCK

#### STATUS_INSTRUCTION_MISALIGNMENT

#### STATUS_DATATYPE_MISALIGNMENT

#### STATUS_PRIVILEGED_INSTRUCTION

#### STATUS_ILLEGAL_INSTRUCTION

#### STATUS_BREAKPOINT

#### STATUS_STACK_OVERFLOW

#### STATUS_HANDLE_NOT_CLOSABLE

#### STATUS_IN_PAGE_ERROR

#### STATUS_ASSERTION_FAILURE

#### STATUS_STACK_BUFFER_OVERRUN

#### STATUS_GUARD_PAGE_VIOLATION

#### STATUS_REG_NAT_CONSUMPTION

## Return value

A value that specifies whether the exception was fatal or non-fatal.

| Return code | Description |
| --- | --- |
| **EXCEPTION_CONTINUE_SEARCH** | The exception is fatal and must be handled. |
| **EXCEPTION_EXECUTE_HANDLER** | The exception is not fatal. |

## Remarks

The recommended usage of **RpcExceptionFilter** is:

```cpp

RpcTry
{
    … RPC calls here …
RpcExcept(RpcExceptionFilter(RpcExceptionCode()))
{
    … error handling here …
}
RpcEndExcept
```

## See also

[Exception Handling](https://learn.microsoft.com/windows/desktop/Rpc/exception-handling)

[RpcExcept](https://learn.microsoft.com/windows/desktop/api/rpc/nf-rpc-rpcexcept)

[RpcExceptionCode](https://learn.microsoft.com/previous-versions/aa375695(v=vs.80))

[RpcTryExcept](https://learn.microsoft.com/windows/desktop/Rpc/rpctryexcept)