# IDebugControl3::GetExpressionSyntax

## Description

The **GetExpressionSyntax** method returns the current syntax that the engine is using for evaluating expressions.

## Parameters

### `Flags` [out]

Receives the expression syntax. It is set to one of the following values:

#### DEBUG_EXPR_MASM

Expressions will be evaluated according to MASM syntax. For details of this syntax, see [MASM Numbers and Operators](https://learn.microsoft.com/windows-hardware/drivers/debugger/masm-numbers-and-operators).

#### DEBUG_EXPR_CPLUSPLUS

Expressions will be evaluated according to C++ syntax. For details of this syntax, see [C++ Numbers and Operators](https://learn.microsoft.com/windows-hardware/drivers/debugger/c---numbers-and-operators).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[Evaluate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-evaluate)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExpressionSyntax](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntax)

[SetExpressionSyntaxByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntaxbyname)