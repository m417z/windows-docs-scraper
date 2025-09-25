# IDebugControl2::GetProcessorTypeNames

## Description

The **GetProcessorTypeNames** method returns the full name and abbreviated name of the specified processor type.

## Parameters

### `Type` [in]

Specifies the type of the processor whose name is requested. See [GetActualProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getactualprocessortype) for a list of possible values.

### `FullNameBuffer` [out, optional]

Receives the full name of the processor type. If *FullNameBuffer* is **NULL**, this information is not returned.

### `FullNameBufferSize` [in]

Specifies the size, in characters, of the buffer that *FullNameBuffer* specifies. This size includes the space for the '\0' terminating character.

### `FullNameSize` [out, optional]

Receives the size in characters of the full name of the processor type. This size includes the space for the '\0' terminating character. If *FullNameSize* is **NULL**, this information is not returned.

### `AbbrevNameBuffer` [out, optional]

Receives the abbreviated name of the processor type. If *AbbrevNameBuffer* is **NULL**, this information is not returned.

### `AbbrevNameBufferSize` [in]

Specifies the size, in characters, of the buffer that *AbbrevNameBuffer* specifies. This size includes the space for the '\0' terminating character.

### `AbbrevNameSize` [out, optional]

Receives the size in characters of the abbreviated name of the processor type. This size includes the space for the '\0' terminating character. If *AbbrevNameSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, at least one of *FullNameBuffer* or *AbbrevNameBuffer* was too small for the corresponding name, so the name was truncated. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetSupportedProcessorTypes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getsupportedprocessortypes)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)