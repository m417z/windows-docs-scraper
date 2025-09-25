# CcScheduleReadAhead function

## Description

The **CcScheduleReadAhead** routine performs read-ahead (also called "lazy read") on a cached file. **CcScheduleReadAhead** should never be called directly. The **CcReadAhead** macro should be called instead.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file on which read-ahead is to be performed.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the last read occurred.

### `Length` [in]

Length in bytes of the range that was last read.

## Remarks

The **CcReadAhead** macro is a wrapper for **CcScheduleReadAhead**. It calls **CcScheduleReadAhead** only if *Length* >= 256. Measurements have shown that calling **CcScheduleReadAhead** for smaller reads actually decreases performance.

**CcReadAhead** and **CcScheduleReadAhead** can only be called after a successful call to [CcCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread), [CcFastCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopyread), or [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)).

## See also

[CcCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread)

[CcFastCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopyread)

[CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85))

[CcScheduleReadAhead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccschedulereadahead)

[CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[CcSetReadAheadGranularity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)