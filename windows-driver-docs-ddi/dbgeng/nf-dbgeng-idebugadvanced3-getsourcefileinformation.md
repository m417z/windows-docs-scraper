# IDebugAdvanced3::GetSourceFileInformation

## Description

The **GetSourceFileInformation** method returns specified information about a source file.

## Parameters

### `Which` [in]

Specifies the piece of information to return. The *Which* parameter can take one of the values in the following table.

#### DEBUG_SRCFILE_SYMBOL_TOKEN

Returns a token representing the specified source file on a source server. This token can be passed to [FindSourceFileAndToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-findsourcefileandtoken) to retrieve information about the file. The token is returned to the *Buffer* buffer as an array of bytes. The size of this token is a reflection of the size of the SrcSrv token.

#### DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE

Queries a source server for the command to extract the source file from source control. This includes the name of the executable file and its command-line parameters. The command is returned to the *Buffer* buffer as a Unicode string.

### `SourceFile` [in]

Specifies the source file whose information is being requested. The source file is looked up on all the source servers in the source path.

### `Arg64` [in]

Specifies a 64-bit argument. The value of *Which* specifies the module whose symbol token is requested. Regardless of the value of *Which*, *Arg64* is a location within the memory allocation of the module.

### `Arg32` [in]

Specifies a 32-bit argument. This parameter is currently unused.

### `Buffer` [out, optional]

Receives the requested symbol information. The type of the data returned depends on the value of *Which*. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in bytes of the *Buffer* buffer. If *Buffer* is **NULL**, *BufferSize* must also be **NULL**.

### `InfoSize` [out, optional]

Specifies the size in bytes of the information returned to the *Buffer* buffer. This parameter can be **NULL** if the data is not required.

##### - Which.DEBUG_SRCFILE_SYMBOL_TOKEN

Returns a token representing the specified source file on a source server. This token can be passed to [FindSourceFileAndToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-findsourcefileandtoken) to retrieve information about the file. The token is returned to the *Buffer* buffer as an array of bytes. The size of this token is a reflection of the size of the SrcSrv token.

##### - Which.DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE

Queries a source server for the command to extract the source file from source control. This includes the name of the executable file and its command-line parameters. The command is returned to the *Buffer* buffer as a Unicode string.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the information would not fit in the *Buffer* buffer, so the information or name was truncated. |

## Remarks

For more information about source files, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[FindSourceFileAndToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-findsourcefileandtoken)

[IDebugAdvanced2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced2)

[IDebugAdvanced3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced3)