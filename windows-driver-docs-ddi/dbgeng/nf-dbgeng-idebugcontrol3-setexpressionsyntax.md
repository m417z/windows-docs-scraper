# IDebugControl3::SetExpressionSyntax

## Description

The **SetExpressionSyntax** method sets the syntax that the engine will use to evaluate expressions.

## Parameters

### `Flags` [in]

Specifies the syntax that the engine will use to evaluate expressions. It can be one of the following values:

#### DEBUG_EXPR_MASM

Expressions will be evaluated according to MASM syntax. For details of this syntax, see [MASM Numbers and Operators](https://learn.microsoft.com/windows-hardware/drivers/debugger/masm-numbers-and-operators).

#### DEBUG_EXPR_CPLUSPLUS

Expressions will be evaluated according to C++ syntax. For details of this syntax, see [C++ Numbers and Operators](https://learn.microsoft.com/windows-hardware/drivers/debugger/c---numbers-and-operators).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The expression syntax is a global setting within the engine, so setting the expression syntax will affect all clients.

The expression syntax of the engine determines how the engine will interpret expressions passed to [Evaluate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-evaluate), [Execute](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-execute), and any other method that evaluates an expression.

After the expression syntax has been changed, the engine sends out notification to the [IDebugEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbacks) registered with each client. It also passes the DEBUG_CES_EXPRESSION_SYNTAX flag to the [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) method.

## See also

[Evaluate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-evaluate)

[GetExpressionSyntax](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexpressionsyntax)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExpressionSyntaxByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntaxbyname)