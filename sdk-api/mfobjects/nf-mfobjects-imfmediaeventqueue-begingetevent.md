# IMFMediaEventQueue::BeginGetEvent

## Description

Begins an asynchronous request for the next event in the queue.

Call this method inside your implementation of [IMFMediaEventGenerator::BeginGetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-begingetevent). Pass the parameters from that method directly to this method.

## Parameters

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-shutdown) method was called. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue)