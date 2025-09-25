# TAPE_GET_MEDIA_PARAMETERS structure

## Description

The
**TAPE_GET_MEDIA_PARAMETERS** structure describes the tape in the tape drive. It is used by the [GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function.

## Members

### `Capacity`

Total number of bytes on the current tape partition.

### `Remaining`

Number of bytes between the current position and the end of the current tape partition.

### `BlockSize`

Number of bytes per block.

### `PartitionCount`

Number of partitions on the tape.

### `WriteProtected`

If this member is **TRUE**, the tape is write-protected. Otherwise, it is not.

## Remarks

The
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function fills the **Remaining** and **Capacity** members with estimates of the tape remaining in the current tape partition and the total capacity of the current tape partition.

## See also

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)