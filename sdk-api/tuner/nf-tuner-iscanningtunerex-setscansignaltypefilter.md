# IScanningTunerEx::SetScanSignalTypeFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

Not implemented in this release.

The **SetScanSignalTypeFilter** method specifies the type of signal to scan for. Applications can optionally call this method before calling [PerformExhaustiveScan](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtunerex-performexhaustivescan), to filter the signal types that the tuner will search for.

## Parameters

### `ScanModulationTypes`

Specifies the modulation types, as a bitwise OR of flags from the [ScanModulationTypes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/scanmodulationtypes) enumeration. If the value is 0xFFFFFFFF, the tuner does not filter out any specific modulation types.

### `AnalogVideoStandard`

Specifies the analog standards, as a bitwise OR of flags from the [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard) enumeration. If the value is 0xFFFFFFFF, the tuner does not filter out any specific analog video standards.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)