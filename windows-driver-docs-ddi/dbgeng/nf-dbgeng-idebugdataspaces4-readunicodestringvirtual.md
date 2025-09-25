# IDebugDataSpaces4::ReadUnicodeStringVirtual

## Description

The **ReadUnicodeStringVirtual** method reads a null-terminated, Unicode string from the target and converts it to a multibyte string.

## Parameters

### `Offset` [in]

Specifies the location in the process's virtual address space of the string.

### `MaxBytes` [in]

Specifies the maximum number of bytes to read from the target.

### `CodePage` [in]

Specifies the code page to use to convert the multibyte string read from the target into a Unicode string. For example, CP_ACP is the ANSI code page.

### `Buffer` [out, optional]

Receives the string from the target. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `StringBytes` [out, optional]

Receives the size, in bytes, of the string in the target. If *StringBytes* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However *Buffer* was not large enough to hold the string and the string was truncated to fit in *Buffer*. The truncated string is null-terminated if *Buffer* has space for at least one character. |
| **E_INVALIDARG** | A null-terminator was not found after reading *MaxBytes* from the target. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The engine will read up to *MaxBytes* from the target, looking for a null-terminator. If the string has more than *BufferSize* characters, the string will be truncated to fit in *Buffer*.

## See also

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadMultiByteStringVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readmultibytestringvirtual)

[ReadUnicodeStringVirtualWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readunicodestringvirtualwide)