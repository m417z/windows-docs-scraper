# IMFMediaEventGenerator::BeginGetEvent

## Description

Begins an asynchronous request for the next event in the queue.

## Parameters

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The client must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** pointer argument. |
| **MF_E_MULTIPLE_BEGIN** | There is a pending request with the same callback pointer and a different state object. |
| **MF_E_MULTIPLE_SUBSCRIBERS** | There is a pending request with a different callback pointer. |
| **MF_E_SHUTDOWN** | The object was shut down. |
| **MF_S_MULTIPLE_BEGIN** | There is a pending request with the same callback pointer and state object. |

## Remarks

When a new event is available, the event generator calls the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The **Invoke** method should call [IMFMediaEventGenerator::EndGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-endgetevent) to get a pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface, and use that interface to examine the event.

Do not call **BeginGetEvent** a second time before calling [EndGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-endgetevent). While the first call is still pending, additional calls to the same object will fail. Also, the [IMFMediaEventGenerator::GetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-getevent) method fails if an asynchronous request is still pending.

#### Examples

The following code shows a typical implementation of [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) for the **BeginGetEvent** method. The **Invoke** method calls [EndGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-endgetevent) to get the event data. Then it calls **BeginGetEvent** again to request another event.

```
//////////////////////////////////////////////////////////////////////
//  Name: CEventHandler::Invoke
//  Callback for asynchronous BeginGetEvent method.
//
//  pAsyncResult: Pointer to the result.
//
//  This code example assumes that CEventHandler is a class that
//  implements the IMFAsyncCallback interface.
///////////////////////////////////////////////////////////////////////
HRESULT CEventHandler::Invoke(IMFAsyncResult *pAsyncResult)
{
    HRESULT hr = S_OK;
    IMFMediaEvent* pEvent = NULL;
    MediaEventType meType = MEUnknown;
    BOOL fGetAnotherEvent = TRUE;
    HRESULT hrStatus = S_OK;

    // Get the event from the event queue.
    // Assume that m_pEventGenerator is a valid pointer to the
    // event generator's IMFMediaEventGenerator interface.
    hr = m_pEventGenerator->EndGetEvent(pAsyncResult, &pEvent);

    // Get the event type.
    if (SUCCEEDED(hr))
    {
        hr = pEvent->GetType(&meType);
    }

    // Get the event status. If the operation that triggered the event
    // did not succeed, the status is a failure code.
    if (SUCCEEDED(hr))
    {
        hr = pEvent->GetStatus(&hrStatus);
    }

    if (SUCCEEDED(hr))
    {
        // TODO: Handle the event.
    }

    // If not finished, request another event.
    // Pass in a pointer to this instance of the application's
    // CEventHandler class, which implements the callback.
    if (fGetAnotherEvent)
    {
        hr = m_pEventGenerator->BeginGetEvent(this, NULL);
    }

    SAFE_RELEASE(pEvent);
    return hr;
}
```

## See also

[IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)