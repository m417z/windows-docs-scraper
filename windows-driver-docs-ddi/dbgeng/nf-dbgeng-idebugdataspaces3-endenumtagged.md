# IDebugDataSpaces3::EndEnumTagged

## Description

The **EndEnumTagged** method releases the resources used by the specified enumeration.

## Parameters

### `Handle` [in]

Specifies the handle identifying the enumeration. This is the handle returned by [StartEnumTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-startenumtagged).

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

After a handle has been passed to this method it is no longer valid and must not be used again.