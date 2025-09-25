# IDebugDataSpaces4::ReadTagged

## Description

The **ReadTagged** method reads the tagged data that might be associated with a debugger session.

## Parameters

### `Tag` [in]

Specifies the GUID identifying the data requested.

### `Offset` [in]

Specifies the offset within the data to read.

### `Buffer` [out, optional]

Receives the data. If *Buffer* is **NULL**, the data is not returned.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be returned.

### `TotalSize` [out, optional]

Receives the total size in bytes of the data specified by *Tag*.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No data identified by *Tag* could be found. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

Some debugger sessions have arbitrary additional data available. For example, when a dump file is created, additional dump information files containing extra information may also be created. This additional data is tagged with a global unique identifier and can only be retrieved via the tag.

LPGUID is a pointer to a 128-bit unique identifier. It is defined in the Microsoft Windows SDK header file guiddef.h.

## See also

[GetNextTagged](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-getnexttagged)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)