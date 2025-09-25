# RpcExcept macro

## Description

The
**RpcExcept** statement provides structured exception handling for RPC applications.

**Windows Vista and later versions of Windows:** [RpcExceptionFilter](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcexceptionfilter) is recommended for structured exception handling for the most common exceptions as an alternative to custom filters with **RpcExcept**. Custom exception filters must still use **RpcExcept**, however.

## Parameters

### `expr`

Expression that is evaluated when an exception occurs. If *expression* evaluates to a nonzero value, the exception statements are executed. If *expression* evaluates to a zero value, unwinding continues to the next
[RpcTryExcept](https://learn.microsoft.com/windows/desktop/Rpc/rpctryexcept) or
[RpcTryFinally](https://learn.microsoft.com/windows/desktop/Rpc/rpctryfinally) function.

## Remarks

If an exception does not occur, the *expression* and *exception statements* are skipped and execution continues at the statement following the
[RpcEndExcept](https://learn.microsoft.com/previous-versions/aa375629(v=vs.80)) statement.

The compound statement after the
**RpcTryExcept** clause is the body or guarded section. The compound statement after the
**RpcExcept** clause is the exception handler. The handler specifies a set of actions to be taken if an exception is raised during execution of the body of the guarded section. Execution proceeds as follows:

1. The guarded section is executed.
2. If no exception occurs during execution of the guarded section, execution continues at the statement after
   **RpcEndExcept** clause.
3. If an exception occurs during execution of the guarded section or in any routine the guarded section calls, the __except expression is evaluated and the value determines how the exception is handled. There are three values:

   * EXCEPTION_CONTINUE_EXECUTION (–1) Exception is dismissed. Continue execution at the point where the exception occurred.
   * EXCEPTION_CONTINUE_SEARCH (0) Exception is not recognized. Continue to search up the stack for a handler, first for containing try-except statements, then for handlers with the next highest precedence.
   * Exception is recognized. Transfer control to the exception handler by executing the __except compound statement, then continue execution after the __except block.

Because the
**RpcExcept** expression is evaluated as a C expression, it is limited to a single value, the conditional-expression operator, or the comma operator. If more extensive processing is required, the expression can call a routine that returns one of the three values listed above.

[RpcExceptionCode](https://learn.microsoft.com/previous-versions/aa375695(v=vs.80)) can be used in both *expression* and *exception statements* to determine which exception occurred.

The following restrictions apply:

* Jumping (through a **goto**) into *guarded statements* is not allowed.
* Jumping (through a **goto**) into *exception statements* is not allowed.
* Returning or jumping (through a **goto**) from *guarded statements* is not allowed.
* Returning or jumping (through a **goto**) from *exception statements* is not allowed.

## See also

[Exception Handling](https://learn.microsoft.com/windows/desktop/Rpc/exception-handling)

[RpcExceptionCode](https://learn.microsoft.com/previous-versions/aa375695(v=vs.80))

[RpcExceptionFilter](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcexceptionfilter)

[RpcFinally](https://learn.microsoft.com/previous-versions/aa375699(v=vs.80))

[RpcRaiseException](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcraiseexception)