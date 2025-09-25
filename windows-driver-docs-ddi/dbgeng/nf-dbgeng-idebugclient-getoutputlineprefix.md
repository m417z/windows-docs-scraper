# IDebugClient::GetOutputLinePrefix

## Description

 Gets the prefix used for multiple lines of output.

## Parameters

### `Buffer` [out]

A pointer to the buffer to get the prefix.

### `BufferSize` [in]

The size of the buffer.

### `PrefixSize` [out, optional]

A pointer to the size of the buffer.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Some of the engine commands produce
multiple lines of output. A prefix can be added to each line.

 The prefix value is not a general setting for any output
that contains a newline. Methods which use
the line prefix are marked in their documentation.

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)