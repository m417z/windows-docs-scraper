# ITuner::TriggerSignalEvents

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **TriggerSignalEvents** method enables the tuner to raise an event when the status of the signal changes.

## Parameters

### `Interval` [in]

Specifies the time-out interval in milliseconds.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

If the signal status does not change by the time that the time-out interval expires, the tuner raises the signal-status-change event at the end of the time-out interval. If the caller specifies the interval to be INFINITE, the tuner does not raise the event until the signal status changes, regardless of how much time elapses before the change occurs. Specifying a value of 0 raises the signal-status-change event immediately, regardless of whether the signal status has changed.

Each call to **TriggerSignalEvents** enables the event to be raised only one time. To raise the event multiple times in response to a series of signal-status changes requires a succession of calls to **TriggerSignalEvents**.

Multiple event sink objects can wait for the tuner to raise an event that occurs when the signal status changes. For more information, see [IBroadcastEvent Interface](https://learn.microsoft.com/previous-versions/dd376294(v=vs.85)).

## See also

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)