# IStreamBufferConfigure2::GetFFTransitionRates

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetFFTransitionRates** method returns the maximum full-frame and key-frame playback rates.

## Parameters

### `pdwMaxFullFrameRate` [out]

Receives the maximum full-frame playback rate. At higher playback rates, only key frames are sent.

### `pdwMaxNonSkippingRate` [out]

Receives the maximum key-frame playback rate. At higher playback rates, some key frames are skipped. The number of key frames that are skipped is proportional to the rate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For more information, see [IStreamBufferConfigure2::SetFFTransitionRates](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferconfigure2-setfftransitionrates).

## See also

[IStreamBufferConfigure2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure2)