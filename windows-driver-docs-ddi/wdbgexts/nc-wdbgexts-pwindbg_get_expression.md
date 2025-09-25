# PWINDBG_GET_EXPRESSION callback function

## Description

The **PWINDBG_GET_EXPRESSION** (**GetExpression**) function returns the value of *expression*. The expression is evaluated using the current expression evaluator, and can contain aliases.

## Parameters

### `lpExpression` [in]

Specifies the expression to evaluate.

## Return value

The value of the expression passed to **GetExpression**

## Remarks

The expression is evaluated by the current expression evaluator (either the MASM or C++ expression evaluator); see [Numerical Expression Syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/numerical-expression-syntax) for details. Aliases will be properly understood; see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases) for details.

If KDEXT_64BIT is defined, this function returns a value of type ULONG64. Otherwise, it returns a value of type ULONG.