# IMFMediaEventGenerator::GetEvent

## Description

Retrieves the next event in the queue. This method is synchronous.

## Parameters

### `dwFlags` [in]

Specifies one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The method blocks until the event generator queues an event. |
| **MF_EVENT_FLAG_NO_WAIT** | The method returns immediately. |

### `ppEvent` [out]

Receives a pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |
| **MF_E_MULTIPLE_SUBSCRIBERS** | There is a pending request. |
| **MF_E_NO_EVENTS_AVAILABLE** | There are no events in the queue. |
| **MF_E_SHUTDOWN** | The object was shut down. |

## Remarks

This method executes synchronously.

If the queue already contains an event, the method returns S_OK immediately. If the queue does not contain an event, the behavior depends on the value of *dwFlags*:

* If *dwFlags* is 0, the method blocks indefinitely until a new event is queued, or until the event generator is shut down.
* If *dwFlags* is MF_EVENT_FLAG_NO_WAIT, the method fails immediately with the return code MF_E_NO_EVENTS_AVAILABLE.

This method returns MF_E_MULTIPLE_SUBSCRIBERS if you previously called [IMFMediaEventGenerator::BeginGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-begingetevent) and have not yet called [IMFMediaEventGenerator::EndGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-endgetevent).

## See also

[IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)