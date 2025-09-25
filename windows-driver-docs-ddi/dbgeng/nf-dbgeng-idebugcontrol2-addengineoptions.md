# IDebugControl2::AddEngineOptions

## Description

The **AddEngineOptions** method turns on some of the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction)'s options.

## Parameters

### `Options` [in]

Specifies engine options to turn on. *Options* is a bit-set that will be combined with the existing engine options using the bitwise-OR operator. For a description of the engine options, see [DEBUG_ENGOPT_XXX](https://learn.microsoft.com/previous-versions/ff541475(v=vs.85)).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

After the engine options have been changed, the engine sends out notification to each client's [event callback object](https://learn.microsoft.com/windows-hardware/drivers/debugger/e) by passing the DEBUG_CES_ENGINE_OPTIONS flag to the [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) method.

## See also

[GetEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getengineoptions)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeengineoptions)

[SetEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setengineoptions)