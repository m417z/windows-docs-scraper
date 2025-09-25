# IMFMediaEventQueue::QueueEvent

## Description

Puts an event in the queue.

## Parameters

### `pEvent` [in]

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of the event to be put in the queue.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-shutdown) method was called. |

## Remarks

Call this method when your component needs to raise an event that contains attributes. To create the event object, call [MFCreateMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemediaevent). Add attributes to the event by using methods from the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. (The [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface inherits **IMFAttributes**.)

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue)