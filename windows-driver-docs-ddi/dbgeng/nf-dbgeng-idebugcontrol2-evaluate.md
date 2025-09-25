# IDebugControl2::Evaluate

## Description

The **Evaluate** method evaluates an expression, returning the result.

## Parameters

### `Expression` [in]

Specifies the expression to be evaluated.

### `DesiredType` [in]

Specifies the desired return type. Possible values are described in [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value); with the addition of DEBUG_VALUE_INVALID, which indicates that the return type should be the expression's natural type.

### `Value` [out]

Receives the value of the expression.

### `RemainderIndex` [out, optional]

Receives the index of the first character of the expression not used in the evaluation. If *RemainderIndex* is **NULL**, this information isn't returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An error occurred while evaluating the expression. For example, there was a syntax error, an undefined variable, or a division by zero exception. |

## Remarks

Expressions are evaluated by the current *expression evaluator*. The engine contains multiple expression evaluators; each supports a different syntax. The current expression evaluator can be chosen by using [SetExpressionSyntax](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntax).

For details of the available expression evaluators and their syntaxes, see [Numerical Expression Syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/numerical-expression-syntax).

If an error occurs while evaluating the expression, returning E_FAIL, the *RemainderIndex* variable can be used to determine approximately where in the expression the error occurred.

## See also

[GetExpressionSyntax](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexpressionsyntax)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExpressionSyntax](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntax)

[SetExpressionSyntaxByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntaxbyname)