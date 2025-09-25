# IDebugDataSpaces4::GetOffsetInformation

## Description

The **GetOffsetInformation** method provides general information about an address in a process's data space.

## Parameters

### `Space` [in]

Specifies the data space to which the *Offset* parameter applies. The allowed values depend on the *Which* parameter.

### `Which` [in]

Specifies which information about the data is being queried. This determines the possible values for *Space* and the type of the data returned in *Buffer*. Possible values are:

#### DEBUG_OFFSINFO_VIRTUAL_SOURCE

Returns the source of the target's virtual memory at *Offset*. This is where the debugger engine reads the memory from. *Space* must be set to DEBUG_DATA_SPACE_VIRTUAL. A ULONG is returned to *Buffer*. This ULONG can take the values listed in the following table.

| Value | Description |
| --- | --- |
| DEBUG_VSOURCE_INVALID | The *Offset* offset is not available in the process's virtual address space.<br><br>This could mean that the address is invalid, or that the memory is unavailable -- for example, a crash-dump file might not contain all of the memory for the process or for the kernel. |
| DEBUG_VSOURCE_DEBUGGEE | The virtual memory at the *Offset* offset is provided by the target. |
| DEBUG_VSOURCE_MAPPED_IMAGE | The debugger engine reads the target's virtual memory at *Offset* offset from a local image file. This is often the case in minidump files where the module images are not included in the dump file and are instead loaded by the debugger engine. |

### `Offset` [in]

Specifies the offset in the target's data space for which the information is returned.

### `Buffer` [out, optional]

Specifies the buffer to receive the information. The type of the data returned depends on the value of *Which*. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in bytes, of the *Buffer* buffer.

### `InfoSize` [out, optional]

Receives the size, in bytes, of the information that is returned. If *InfoSize* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |