# IDebugDataSpaces::SearchVirtual

## Description

The **SearchVirtual** method searches the target's virtual memory for a specified pattern of bytes.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space to start searching for the pattern.

### `Length` [in]

Specifies how far to search for the pattern. A successful match requires the entire pattern to be found before *Length* bytes have been examined.

### `Pattern` [in]

Specifies the pattern to search for.

### `PatternSize` [in]

Specifies the size in bytes of the pattern. This must be a multiple of the granularity of the pattern.

### `PatternGranularity` [in]

Specifies the granularity of the pattern. For a successful match the pattern must occur a multiple of this value after the start location.

### `MatchOffset` [out]

Receives the location in the target's virtual address space of the pattern, if it was found.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **HRESULT_FROM_NT(STATUS_NO_MORE_ENTRIES)** | After examining *Length* bytes the pattern was not found. |

## Remarks

This method searches the target's virtual memory for the first occurrence, subject to granularity, of the pattern entirely contained in the *Length* bytes of the target's memory starting at the location *Offset*.

*PatternGranularity* can be used to ensure the alignment of the match relative to *Offset*. For example, a value of 0x4 can be used to require alignment to a DWORD. A value of 0x1 can be used to allow the pattern to start anywhere.

For additional options, including the ability to restrict the search to writable memory, see [SearchVirtual2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-searchvirtual2).

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual)

[SearchVirtual2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-searchvirtual2)