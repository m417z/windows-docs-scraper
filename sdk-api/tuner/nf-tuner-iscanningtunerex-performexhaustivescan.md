# IScanningTunerEx::PerformExhaustiveScan

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **PerformExhaustiveScan** method scans a range of frequencies until the tuner locks onto a signal.

## Parameters

### `dwLowerFreq` [in]

Lowest frequency in the range of frequencies to scan. A value of -1 specifies the minimum frequency as determined by the device.

### `dwHigherFreq` [in]

Highest frequency in the range of frequencies to scan. A value of -1 specifies the maximum frequency as determined by the device.

### `bFineTune` [in]

Specifies whether the tuner performs fine tuning. When the tuner locks onto a frequency, if this parameter is **VARIANT_TRUE**, the tuner does fine tuning to find the best possible signal around that frequency.

### `hEvent` [in]

Handle to an event created by the application. When the tuner locks onto a signal, it signals this event.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_FALSE | No scan is currently in progress. |
| E_INVALIDARG | Invalid frequency argument (for example, 0 *dwLowerFrequency* or *dwHigherFreq* value or *dwLowerFrequency* >= *dwHigherFreq*). |
| S_OK | Success. |

## Remarks

This method is asynchronous.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)