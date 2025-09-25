# IMFRateSupport::IsRateSupported

## Description

Queries whether the object supports a specified playback rate.

## Parameters

### `fThin` [in]

If **TRUE**, the method queries whether the object supports the playback rate with thinning. Otherwise, the method queries whether the object supports the playback rate without thinning. For information about thinning, see [About Rate Control](https://learn.microsoft.com/windows/desktop/medfound/about-rate-control).

### `flRate` [in]

The playback rate to query.

### `pflNearestSupportedRate` [in, out]

If the object does not support the playback rate given in *flRate*, this parameter receives the closest supported playback rate. If the method returns S_OK, this parameter receives the value given in *flRate*. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The object supports the specified rate. |
| **MF_E_REVERSE_UNSUPPORTED** | The object does not support reverse playback. |
| **MF_E_THINNING_UNSUPPORTED** | The object does not support thinning. |
| **MF_E_UNSUPPORTED_RATE** | The object does not support the specified rate. |

## See also

[How to Determine Supported Rates](https://learn.microsoft.com/windows/desktop/medfound/how-to-determine-supported-rates)

[IMFRateSupport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratesupport)