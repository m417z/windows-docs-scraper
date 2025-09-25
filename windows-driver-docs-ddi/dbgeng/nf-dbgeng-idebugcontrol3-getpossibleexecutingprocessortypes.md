# IDebugControl3::GetPossibleExecutingProcessorTypes

## Description

The **GetPossibleExecutingProcessorTypes** method returns the processor types that are supported by the computer running the current target.

## Parameters

### `Start` [in]

Specifies the index of the first processor type to return. The processor types are indexed by numbers zero through to the number of processor types supported by the current target minus one. The number of processor types supported by the current target can be found using [GetNumberPossibleExecutingProcessorTypes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberpossibleexecutingprocessortypes).

### `Count` [in]

Specifies how many processor types to return.

### `Types` [out]

Receives the list of processor types. The number of elements this array holds is *Count*. For a description of the processor types see [GetActualProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getactualprocessortype).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetActualProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getactualprocessortype)

[GetNumberPossibleExecutingProcessorTypes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberpossibleexecutingprocessortypes)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)