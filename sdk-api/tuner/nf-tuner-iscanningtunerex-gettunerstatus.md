# IScanningTunerEx::GetTunerStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **GetTunerStatus** method returns the current status of the most recent call to [PerformExhaustiveScan](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtunerex-performexhaustivescan).

## Parameters

### `SecondsLeft` [out]

Receives the estimated number of seconds remaining for the scan to complete.

### `CurrentLockType` [out]

Receives a member of the [TunerLockType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tunerlocktype) enumeration, indicating how well the tuner locked onto a signal.

### `AutoDetect` [out]

Receives a Boolean value. If the value is **TRUE**, the tuner is in auto-detect mode.

### `CurrentFreq` [out]

Receives the frequency that was most recently scanned.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

While the scan is in progress, the application can use this method to estimate the total time required for the scan to complete. When the tuner locks onto a frequency and sets the application's event handle, the application can use this method to find the locked frequency.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)