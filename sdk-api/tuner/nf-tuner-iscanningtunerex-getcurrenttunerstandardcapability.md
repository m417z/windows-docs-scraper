# IScanningTunerEx::GetCurrentTunerStandardCapability

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **GetCurrentTunerStandardCapability** method retrieves the tuner's capabilities for a specified broadcast standard.

## Parameters

### `CurrentBroadcastStandard` [in]

GUID that specifies the broadcast standard to query. To find the broadcast standards supported by the tuner, call [GetTunerScanningCapability](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtunerex-gettunerscanningcapability).

### `SettlingTime` [out]

Receives the approximate amount of time the tuner requires to tune to a frequency, in milliseconds.

### `TvStandardsSupported` [out]

If *CurrentBroadcastStandard* is ANALOG_TV_NETWORK_TYPE, this parameter receives a bitwise OR of flags from the [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard) enumeration, indicating which analog television formats are supported by the tuner. Otherwise, this parameter is ignored.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)