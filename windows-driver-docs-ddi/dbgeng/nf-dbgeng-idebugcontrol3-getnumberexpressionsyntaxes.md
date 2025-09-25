# IDebugControl3::GetNumberExpressionSyntaxes

## Description

The **GetNumberExpressionSyntaxes** method returns the number of expression syntaxes that are supported by the engine.

## Parameters

### `Number` [out]

Receives the number of expression syntaxes.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[Evaluate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-evaluate)

[GetExpressionSyntaxNames](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexpressionsyntaxnames)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExpressionSyntaxByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexpressionsyntaxbyname)