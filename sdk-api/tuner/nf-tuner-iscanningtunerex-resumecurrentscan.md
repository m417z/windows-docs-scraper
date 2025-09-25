# IScanningTunerEx::ResumeCurrentScan

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **ResumeCurrentScan** method resumes scanning the range of frequencies specified in [PerformExhaustiveScan](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtunerex-performexhaustivescan).

## Parameters

### `hEvent` [in]

Handle to an event created by the application. When the tuner locks onto a signal, it signals this event.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_FALSE | No scan has been started yet. |
| E_INVALIDARG | Invalid *hEvent* argument. |
| S_OK | Success. |

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

When the application calls **PerformExhaustiveScan**, the tuner scans until it locks onto a signal. Then it sets the application's event handle. To resume scanning for the next valid signal in original range of frequencies, the application can call **ResumeCurrentScan**.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)