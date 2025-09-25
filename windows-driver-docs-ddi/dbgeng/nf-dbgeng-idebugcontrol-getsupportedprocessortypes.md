# IDebugControl::GetSupportedProcessorTypes

## Description

The **GetSupportedProcessorTypes** method returns the processor types supported by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

## Parameters

### `Start` [in]

Specifies the index of the first processor type to return. The supported processor types are indexed by the numbers zero through the number of supported processor types minus one. The number of supported processor types can be found using [GetNumberSupportedProcessorTypes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbersupportedprocessortypes).

### `Count` [in]

Specifies the number of processor types to return.

### `Types` [out]

Receives the list of processor types. The number of elements this array holds is *Count*. For a description of the processor types, see [GetActualProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getactualprocessortype).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetNumberSupportedProcessorTypes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbersupportedprocessortypes)

[GetProcessorTypeNames](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getprocessortypenames)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)