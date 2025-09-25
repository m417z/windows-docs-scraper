# NdisGetDataBuffer function

## Description

Call the
**NdisGetDataBuffer** function to gain access to a contiguous block of data from a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Parameters

### `NetBuffer` [in]

A pointer to a NET_BUFFER structure.

### `BytesNeeded` [in]

The number of contiguous bytes of data requested.

### `Storage` [in, optional]

A pointer to a buffer, or **NULL** if no buffer is provided by the caller. The buffer must be greater
than or equal in size to the number of bytes specified in
*BytesNeeded* . If this value is non-**NULL**, and the data requested is not contiguous, NDIS copies the
requested data to the area indicated by
*Storage* .

### `AlignMultiple` [in]

The alignment multiple expressed in power of two. For example, 2, 4, 8, 16, and so forth. If
*AlignMultiple* is 1, then there is no alignment requirement.

### `AlignOffset` [in]

The offset, in bytes, from the alignment multiple.

## Return value

**NdisGetDataBuffer** returns a pointer to the start of the contiguous data or it returns **NULL**.

If the
**DataLength** member of the
[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure in the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure that the *NetBuffer*
parameter points to is less than the value in the
*BytesNeeded* parameter, the return value is **NULL**.

If the requested data in the buffer is contiguous, the return value is a pointer to a location that
NDIS provides. If the data is not contiguous, NDIS uses the
*Storage* parameter as follows:

* If the
  *Storage* parameter is non-**NULL**, NDIS copies the data to the buffer at
  *Storage*. The return value is the pointer passed to the
  *Storage* parameter.
* If the
  *Storage* parameter is **NULL**, the return value is **NULL**.

The return value can also be **NULL** due to a low resource condition where a data buffer cannot be mapped. This may occur even if the data is contiguous or the *Storage* parameter is non-**NULL**.

## Remarks

Call this function to get a pointer to a network data header contained in the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. You can easily parse the
header stored in the contiguous data block that this function returns.

The requested alignment requirement is expressed as a power-of-two multiple plus an offset. For
example, if
*AlignMultiple* is 4 and
*AlignOffset* is 3 then the data address should be a multiple of 4 plus 3. If necessary, NDIS will
allocate memory to satisfy the alignment requirement.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data)