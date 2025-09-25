# IScanningTunerEx::GetTunerScanningCapability

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **GetTunerScanningCapability** method retrieves the set of broadcast standards supported by the tuner and the tuner's scanning capability.

## Parameters

### `HardwareAssistedScanning` [out]

Receives a Boolean value. If the value is **TRUE**, the scanning algorithm is implemented entirely by the tuner hardware. Otherwise, the tuner filter implements part of the scanning algorithm in software.

### `NumStandardsSupported` [out]

Receives the number of broadcast standards supported by the tuner.

### `BroadcastStandards` [out]

Pointer to an array of GUIDs. The array must be large enough to hold a number of elements equal to the value returned in the *NumStandardsSupported* parameter. To find the required array size, call the method once and set this parameter to **NULL**. Then allocate the array and call the method again, setting this parameter to the address of the array.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The following broadcast standard GUIDs are defined in Bdamedia.h.

| **GUID** | Description |
| --- | --- |
| ANALOG_AUXIN_NETWORK_TYPE | Auxiliary video input |
| ANALOG_FM_NETWORK_TYPE | FM radio tuner |
| ANALOG_TV_NETWORK_TYPE | Analog television |
| DIGITAL_CABLE_NETWORK_TYPE | Digital cable |

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)