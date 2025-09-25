# IScanningTuner::AutoProgram

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **AutoProgram** method scans for all channels with valid programming.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

This method returns immediately, and the scan continues in the background. If the device allows it, the scan can be canceled by calling any other tuning operation. Otherwise, the scan will complete once all channels have been visited once. Internal devices will likely have a software implementation of this feature, and will collect fine-tuning information resulting from the scan. External devices will likely implement this feature, so this is just a means to trigger the process.

Currently the DVB-C and DVB-S Network Provider filters do not implement this method, and return E_NOTIMPL. The method is implemented for DVB-T.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IScanningTuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtuner)