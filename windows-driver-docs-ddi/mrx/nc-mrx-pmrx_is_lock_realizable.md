# PMRX_IS_LOCK_REALIZABLE callback function

## Description

The **MRxIsLockRealizable** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector indicate whether a specific byte-range lock is supported on this NET_ROOT structure.

## Parameters

### `Fcb`

[in, out] A pointer to the FCB structure.

### `ByteOffset`

[in] A value indicating the byte offset for the byte range lock.

### `Length`

[in] A value indicating the length for the byte range lock.

### `LowIoLockFlags`

[in] A value with a bitmask indicating the I/O lock flags.

## Return value

**MRxIsLockRealizable** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_NOT_SUPPORTED | The byte range lock that is requested is not supported. A network mini-redirector would return this value for a lock request that is not supported even if other types of byte range locks are supported. Unsupported locks might include 64-bit locks (the **ByteOffset->HighPart** member is nonzero), zero-length locks (the **Length** parameter is zero), or shared locks (the LOWIO_LOCKSFLAG_EXCLUSIVELOCK bit of the **LowIoLockFlags** parameter is not set).

## Remarks

**MRxIsLockRealizable** determines whether the specific byte-range lock requested is supported on this NET_ROOT structure. A network mini-redirector might support certain byte range locks and not support others. For example, a network mini-redirector might only support 32-bit byte range locks or exclusive locks.

**MRxIsLockRealizable** is called in response to receiving an IRP with the IRP_MN_LOCK minor function.

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fcb)

[**MRxDeallocateForFobx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fobx)

[**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown)

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)