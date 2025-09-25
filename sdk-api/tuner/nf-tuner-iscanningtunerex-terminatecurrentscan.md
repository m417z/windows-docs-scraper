# IScanningTunerEx::TerminateCurrentScan

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **TerminateCurrentScan** method interrupts the current scan, if a scan is in progress.

## Parameters

### `pcurrentFreq` [out]

Receives the last frequency that the tuner scanned before halting.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_FALSE | No scan is currently in progress. |
| S_OK | Success. |

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)