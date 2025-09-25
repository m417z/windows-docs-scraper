# GetExpressionEx function

## Description

The **GetExpressionEx** function evaluates an expression. The expression is evaluated using the MASM evaluator, and can contain aliases.

## Parameters

### `Expression`

Specifies the expression to evaluate. The expression uses the MASM syntax. For details of this syntax, see [MASM Numbers and Operators](https://learn.microsoft.com/windows-hardware/drivers/debugger/masm-numbers-and-operators).

### `Value`

Receives the value of the expression.

### `Remainder`

Receives a pointer to the first character in the expression *Expression* that was not used in the evaluation of the expression.

## Return value

**GetExpressionEx** returns one of the following values:

| Return code | Description |
| --- | --- |
| **TRUE** | The expression was evaluated successfully. |
| **FALSE** | An error occurred while attempting to evaluate the expression. |

## See also

[GetExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_get_expression)