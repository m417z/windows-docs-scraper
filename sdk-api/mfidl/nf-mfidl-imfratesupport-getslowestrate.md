# IMFRateSupport::GetSlowestRate

## Description

Retrieves the slowest playback rate supported by the object.

## Parameters

### `eDirection` [in]

Specifies whether to query to the slowest forward playback rate or reverse playback rate. The value is a member of the [MFRATE_DIRECTION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfrate_direction) enumeration.

### `fThin` [in]

If **TRUE**, the method retrieves the slowest thinned playback rate. Otherwise, the method retrieves the slowest non-thinned playback rate. For information about thinning, see [About Rate Control](https://learn.microsoft.com/windows/desktop/medfound/about-rate-control).

### `pflRate` [out]

Receives the slowest playback rate that the object supports.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_REVERSE_UNSUPPORTED** | The object does not support reverse playback. |
| **MF_E_THINNING_UNSUPPORTED** | The object does not support thinning. |

## Remarks

The value returned in *plfRate* represents a lower bound. Playback at this rate is not guaranteed. Call [IMFRateSupport::IsRateSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfratesupport-isratesupported) to check whether the boundary rate is supported. For example, a component that supports arbitrarily slow rates will return zero in *pflRate*, and applications should call **IsRateSupported** separately to determine whether the component supports rate 0.

If *eDirection* is MFRATE_REVERSE, the method retrieves the slowest reverse playback rate. This is a negative value, assuming the object supports reverse playback.

## See also

[How to Determine Supported Rates](https://learn.microsoft.com/windows/desktop/medfound/how-to-determine-supported-rates)

[IMFRateSupport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratesupport)