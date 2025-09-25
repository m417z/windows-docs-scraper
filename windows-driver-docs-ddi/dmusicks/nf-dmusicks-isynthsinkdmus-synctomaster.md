# ISynthSinkDMus::SyncToMaster

## Description

The `SyncToMaster` method allows synchronization to the master clock in order to avoid drift.

## Parameters

### `rfTime` [in]

Specifies the reference time from the master clock. Reference time is measured in 100-nanosecond units.

### `fStart` [in]

Specifies whether the sample clock is to be reset to zero with this reference time. If **TRUE**, the sample clock must be reset to zero at time *rtTime*. If **FALSE**, the sample clock is not reset.

## Return value

`SyncToMaster` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Because the master time and sample time might be driven by different crystals, they can drift apart. The port driver periodically calls this method to give the miniport driver an opportunity to synchronize its sample clock to the master clock.

Parameter *fStart* is **TRUE** during the first call to `SyncToMaster` after the stream enters the KSSTATE_RUN state (see [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)). Otherwise, *fStart* is **FALSE**.

## See also

[ISynthSinkDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-isynthsinkdmus)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)