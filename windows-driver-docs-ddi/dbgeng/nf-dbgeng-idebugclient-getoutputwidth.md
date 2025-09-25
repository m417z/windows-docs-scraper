# IDebugClient::GetOutputWidth

## Description

Gets the width of an output line for
commands that produce formatted output.

## Parameters

### `Columns` [out]

The number of columns in the output.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This setting is a suggestion that can be overridden by other settings.

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)