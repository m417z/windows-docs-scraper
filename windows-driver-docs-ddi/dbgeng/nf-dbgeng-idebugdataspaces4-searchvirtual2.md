# IDebugDataSpaces4::SearchVirtual2

## Description

The **SearchVirtual2** method searches the process's virtual memory for a specified pattern of bytes.

## Parameters

### `Offset` [in]

Specifies the location in the process's virtual address space to start searching for the pattern.

### `Length` [in]

Specifies how far to search for the pattern. A successful match requires the entire pattern to be found before *Length* bytes have been examined.

### `Flags` [in]

Specifies a bit field of flags for the search. Currently, the only bit-flag that can be set is DEBUG_VSEARCH_WRITABLE_ONLY, which restricts the search to writable memory.

### `Pattern` [in]

Specifies the pattern to search for.

### `PatternSize` [in]

Specifies the size, in bytes, of the pattern. This must be a multiple of the granularity of the pattern.

### `PatternGranularity` [in]

Specifies the granularity of the pattern. For a successful match, the difference between the location of the found pattern and *Offset* must be a multiple of *PatternGranularity*.

### `MatchOffset` [out]

Receives the location in the process's virtual address space of the pattern, if it was found.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **HRESULT_FROM_NT(STATUS_NO_MORE_ENTRIES)** | After examining *Length* bytes, the pattern was not found. |

## Remarks

This method searches the target's virtual memory for the first occurrence, subject to granularity, of the pattern that is entirely contained in the *Length* bytes of the target's memory, starting at the *Offset* location.

*PatternGranularity* can be used to ensure the alignment of the match relative to *Offset*. For example, a value of 0x4 can be used to require alignment to a DWORD. A value of 0x1 can be used to allow the pattern to start anywhere.

## See also

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[SearchVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-searchvirtual)