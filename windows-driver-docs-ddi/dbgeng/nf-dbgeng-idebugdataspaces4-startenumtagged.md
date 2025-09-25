# IDebugDataSpaces4::StartEnumTagged

## Description

The **StartEnumTagged** method initializes an enumeration over the tagged data associated with a debugger session.

## Parameters

### `Handle` [out]

Receives the handle identifying the enumeration. This handle can be passed to [GetNextTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-getnexttagged) and [EndEnumTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-endenumtagged).

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The resources held by an enumeration created with this method can be released using [EndEnumTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-endenumtagged).