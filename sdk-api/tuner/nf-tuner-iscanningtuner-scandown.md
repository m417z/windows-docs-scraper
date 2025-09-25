# IScanningTuner::ScanDown

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **ScanDown** method changes the channel to the next lower channel with valid programming, pauses for the specified number of milliseconds, then repeats until canceled.

## Parameters

### `MillisecondsPause` [in]

The number of milliseconds to pause.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The call returns immediately, while the scan continues in the background. The scan can be canceled by calling any other tuning operation.

Currently the DVB-C and DVB-S Network Provider filters do not implement this method, and return E_NOTIMPL. The method is implemented for DVB-T.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IScanningTuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtuner)