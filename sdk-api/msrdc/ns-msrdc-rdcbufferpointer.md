# RdcBufferPointer structure

## Description

The **RdcBufferPointer** structure describes a
buffer.

## Members

### `m_Size`

Size, in bytes, of the buffer.

### `m_Used`

For input buffers, [IRdcComparator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdccomparator-process)
and [IRdcGenerator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgenerator-process) will store here how
much (if any) of the buffer was used during processing.

### `m_Data`

Pointer to the buffer.

## See also

[Remote Differential Compression Structures](https://learn.microsoft.com/previous-versions/windows/desktop/rdc/remote-differential-compression-structures)