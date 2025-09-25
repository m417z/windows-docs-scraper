# IDebugClient4::GetDumpFile

## Description

The **GetDumpFile** method describes the files containing supporting information that were used when opening the current dump target.

## Parameters

### `Index` [in]

Specifies which file to describe. *Index* can take values between zero and the number of files minus one; the number of files can be found by using [GetNumberDumpFiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberdumpfiles).

### `Buffer` [out, optional]

Receives the file name. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size of the file name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

### `Handle` [out, optional]

Receives the file handle of the file. If *Handle* is **NULL**, this information is not returned.

### `Type` [out]

Receives the type of the file.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about crash dump files, see [Dump-File Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/dump-file-targets).

## See also

[AddDumpInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfile)

[AddDumpInformationFileWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-adddumpinformationfilewide)

[GetNumberDumpFiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberdumpfiles)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)