# NdisCopyFromNetBufferToNetBuffer function

## Description

Call the
**NdisCopyFromNetBufferToNetBuffer** function to copy data from a source
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure to a destination NET_BUFFER
structure.

## Parameters

### `Destination` [in]

A pointer to a previously allocated destination NET_BUFFER structure.

### `DestinationOffset` [in]

The byte offset within the destination NET_BUFFER structure at which to begin writing the copied
data. For more information about
*DestinationOffset*, see the following Remarks section.

### `BytesToCopy` [in]

The number of bytes to copy.

### `Source` [in]

A pointer to a previously allocated source NET_BUFFER structure.

### `SourceOffset` [in]

The byte offset within the source NET_BUFFER structure at which to begin copying the data. For
more information about
*SourceOffset*, see the following Remarks section.

### `BytesCopied` [out]

A pointer to the caller-supplied variable in which this function returns the number of bytes
actually copied. This number can be less than the value of
*BytesToCopy* if the source runs out of data or the destination runs out of space.

## Return value

**NdisCopyFromNetBufferToNetBuffer** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The copy operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The copy operation failed because of insufficient resources. |

## Remarks

The caller of
**NdisCopyFromNetBufferToNetBuffer** allocates the destination
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure and possibly the source
NET_BUFFER structure as well. The MDLs of the destination NET_BUFFER structure should have enough space
to receive the data.

If the source NET_BUFFER structure runs out of data or the destination NET_BUFFER structure runs out
of space before the specified number of bytes has been copied, the copy operation stops. In either case,
**NdisCopyFromNetBufferToNetBuffer** returns the number of bytes successfully copied from the source to
the destination NET_BUFFER structure.

The caller must ensure that
**CurrentMdlOffset** and
**CurrentMdl** values are correct in the source and destination
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. NDIS does not change the
members in the destination NET_BUFFER. The caller must update the
**DataLength**,
**DataOffset**, and
**CurrentMdlOffset** values in the destination NET_BUFFER after
**NdisCopyFromNetBufferToNetBuffer** returns.

NDIS uses the offsets in the
*DestionationOffset* and
*SourceOffset* parameters of
**NdisCopyFromNetBufferToNetBuffer** as offsets from the current data offset. For example, if the
**CurrentMdlOffset** value in the destination NET_BUFFER is
*x*, and
*DestinationOffset* value is
*y*, NDIS copies the data to the destination NET_BUFFER at an
*x*+
*y* offset in the memory that the
**CurrentMdl** value describes. Similar rules apply to the
**CurrentMdlOffset** in the source NET_BUFFER and the
*SourceOffset* value.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)