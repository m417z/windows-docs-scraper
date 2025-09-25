# IMFMediaEventGenerator::EndGetEvent

## Description

Completes an asynchronous request for the next event in the queue.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `ppEvent` [out]

Receives a pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The object was shut down. |

## Remarks

Call this method from inside your application's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. For example code, see [IMFMediaEventGenerator::BeginGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-begingetevent).

## See also

[IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)