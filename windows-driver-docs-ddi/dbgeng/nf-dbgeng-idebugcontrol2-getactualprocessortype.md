# IDebugControl2::GetActualProcessorType

## Description

The **GetActualProcessorType** method returns the processor type of the physical processor of the computer that is running the target.

## Parameters

### `Type` [out]

Receives the type of the processor. The processor types are listed in the following table.

| Value | Processor |
| --- | --- |
| IMAGE_FILE_MACHINE_I386 | x86 architecture |
| IMAGE_FILE_MACHINE_ARM | ARM architecture |
| IMAGE_FILE_MACHINE_IA64 | Intel Itanium architecture |
| IMAGE_FILE_MACHINE_AMD64 | x64 architecture |
| IMAGE_FILE_MACHINE_EBC | EFI byte code architecture |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetEffectiveProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-geteffectiveprocessortype)

[GetExecutingProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexecutingprocessortype)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)