# IDebugDataSpaces4::GetNextTagged

## Description

The **GetNextTagged** method returns the GUID for the next block of tagged data in the enumeration.

## Parameters

### `Handle` [in]

Specifies the handle identifying the enumeration. This is the handle returned by [StartEnumTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-startenumtagged).

### `Tag` [out]

Receives the GUID identifying the tagged data. The data may be retrieved by passing this GUID to [ReadTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readtagged).

### `Size` [out]

Receives the size of the data identified by the GUID *Tag*.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | There are no more blocks of tagged data available in this enumeration. |

## See also

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readtagged)

[StartEnumTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-startenumtagged)