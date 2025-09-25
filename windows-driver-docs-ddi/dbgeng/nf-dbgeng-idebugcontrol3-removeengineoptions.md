# IDebugControl3::RemoveEngineOptions

## Description

The **RemoveEngineOptions** method turns off some of the engine's options.

## Parameters

### `Options` [in]

Specifies the engine options to turn off. *Options* is a bit-set; the new value of the engine's options will equal the bitwise-NOT of *Options* combined with old value using the bitwise-AND operator (`new_value := old_value AND NOT Options`). For a description of the engine options, see [DEBUG_ENGOPT_XXX](https://learn.microsoft.com/previous-versions/ff541475(v=vs.85)).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

After the engine options have been changed, the engine sends out notification to each client's event callback object by passing the DEBUG_CES_ENGINE_OPTIONS flag to the [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) method.

## See also

[AddEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addengineoptions)

[GetEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getengineoptions)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetEngineOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setengineoptions)