# IMFMediaEventQueue::QueueEventParamVar

## Description

Creates an event, sets a **PROPVARIANT** as the event data, and puts the event in the queue.

Call this method inside your implementation of [IMFMediaEventGenerator::QueueEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventgenerator-queueevent). Pass the parameters from that method directly to this method.

You can also call this method when your component needs to raise an event that does not contain attributes. If the event data is an **IUnknown** pointer, you can use [IMFMediaEventQueue::QueueEventParamUnk](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-queueeventparamunk). If the event contains attributes, use [IMFMediaEventQueue::QueueEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaeventqueue-queueevent) instead.

## Parameters

### `met` [in]

Specifies the type of the event to be added to the queue. The event type is returned by the event's [IMFMediaEvent::GetType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-gettype) method. For a list of event types, see [Media Foundation Events](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-events).

### `guidExtendedType` [in]

The extended type of the event. If the event does not have an extended type, use the value GUID_NULL. The extended type is returned by the event's [IMFMediaEvent::GetExtendedType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getextendedtype) method.

### `hrStatus` [in]

A success or failure code indicating the status of the event. This value is returned by the event's [IMFMediaEvent::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getstatus) method.

### `pvValue` [in]

Pointer to a **PROPVARIANT** that contains the event value. This parameter can be **NULL**. This value is returned by the event's [IMFMediaEvent::GetValue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getvalue) method.

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