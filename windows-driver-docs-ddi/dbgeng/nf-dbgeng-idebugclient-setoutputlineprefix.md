# IDebugClient::SetOutputLinePrefix

## Description

 Sets a prefix for multiple lines of output.

## Parameters

### `Prefix` [in, optional]

A pointer to the prefix value.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Some of the engine commands produce
multiple lines of output. This function sets a prefix that the engine adds to each line. This function allows the caller to control indentation or identifying marks.

 The prefix value is not a general setting for any output
that contains a newline. Methods which use
the line prefix are marked in their documentation.

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)