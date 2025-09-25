# CcScheduleReadAheadEx function

## Description

The **CcScheduleReadAheadEx** routine performs read-ahead (also called "lazy read") on a cached file. The I/O byte count for the operation is charged to the issuing thread.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file on which read-ahead is to be performed.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the last read occurred.

### `Length` [in]

Length in bytes of the range that was last read.

### `IoIssuerThread` [in]

The thread issuing the read ahead request. For a file system with disk I/O accounting enabled, this is the thread the I/O is charged to. If **IoIssuerThread** is NULL, the I/O is charged to the current thread.

## Remarks

**CcScheduleReadAheadEx** should be called only when **Length** >= 256. Measurements have shown that calling **CcScheduleReadAheadEx** for smaller reads actually decreases performance.

**CcScheduleReadAheadEx** can only be called after a successful call to [**CcCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread), [**CcCopyReadEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyreadex), [**CcFastCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopyread), or [**CcMdlRead**](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)).

## See also

[**CcCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread)

[**CcCopyReadEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyreadex)

[**CcFastCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopyread)

[**CcMdlRead**](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)).

[**CcReadAhead**](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[**CcSetAdditionalCacheAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[**CcSetReadAheadGranularity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)