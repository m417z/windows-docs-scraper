# IMFMediaEventQueue::GetEvent

## Description

Retrieves the next event in the queue. This method is synchronous.

Call this method inside your implementation of [IMFMediaEventGenerator::GetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-getevent). Pass the parameters from that method directly to this method.

## Parameters

### `dwFlags` [in]

Specifies whether the method blocks until an event is queued. For a list of valid flags, see [IMFMediaEventGenerator::GetEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-getevent).

### `ppEvent` [out]

Receives a pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface.

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