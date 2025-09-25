# RdcNeed structure

## Description

The **RdcNeed** structure contains information about a
chunk that is required to synchronize two sets of data.

## Members

### `m_BlockType`

Describes the type of data needed—source data or seed data.

### `m_FileOffset`

Offset, in bytes, from the start of the data where the chunk should be copied from.

### `m_BlockLength`

Length, in bytes, of the chunk of data that is to be copied to the target data.

## See also

[RdcNeedPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneedpointer)

[RdcNeedType](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdcneedtype)

[Remote Differential Compression Structures](https://learn.microsoft.com/previous-versions/windows/desktop/rdc/remote-differential-compression-structures)