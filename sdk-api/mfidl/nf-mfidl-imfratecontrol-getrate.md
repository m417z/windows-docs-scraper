# IMFRateControl::GetRate

## Description

Gets the current playback rate.

## Parameters

### `pfThin` [in, out]

Receives the value **TRUE** if the stream is currently being thinned. If the object does not support thinning, this parameter always receives the value **FALSE**. This parameter can be **NULL**. For more information, see [About Rate Control](https://learn.microsoft.com/windows/desktop/medfound/about-rate-control).

### `pflRate` [in, out]

Receives the current playback rate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[How to Determine Supported Rates](https://learn.microsoft.com/windows/desktop/medfound/how-to-determine-supported-rates)

[IMFRateControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratecontrol)