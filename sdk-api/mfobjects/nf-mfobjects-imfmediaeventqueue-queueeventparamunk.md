# IMFMediaEventQueue::QueueEventParamUnk

## Description

Creates an event, sets an **IUnknown** pointer as the event data, and puts the event in the queue.

## Parameters

### `met` [in]

Specifies the event type of the event to be added to the queue. The event type is returned by the event's [IMFMediaEvent::GetType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-gettype) method. For a list of event types, see [Media Foundation Events](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-events).

### `guidExtendedType` [in]

The extended type of the event. If the event does not have an extended type, use the value GUID_NULL. The extended type is returned by the event's [IMFMediaEvent::GetExtendedType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getextendedtype) method.

### `hrStatus` [in]

A success or failure code indicating the status of the event. This value is returned by the event's [IMFMediaEvent::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getstatus) method.

### `pUnk` [in]

Pointer to the **IUnknown** interface. The method sets this pointer as the event value. The pointer is returned by the event's [IMFMediaEvent::GetValue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getvalue) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-shutdown) method was called. |

## Remarks

Call this method when your component needs to raise an event that contains an **IUnknown** pointer value and no attributes. If the event contains attributes, use [IMFMediaEventQueue::QueueEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-queueevent) instead.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue)