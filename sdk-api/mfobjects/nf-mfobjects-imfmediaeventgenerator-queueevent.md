# IMFMediaEventGenerator::QueueEvent

## Description

Puts a new event in the object's queue.

## Parameters

### `met` [in]

Specifies the event type. The event type is returned by the event's [IMFMediaEvent::GetType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-gettype) method. For a list of event types, see [Media Foundation Events](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-events).

### `guidExtendedType` [in]

The extended type. If the event does not have an extended type, use the value GUID_NULL. The extended type is returned by the event's [IMFMediaEvent::GetExtendedType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getextendedtype) method.

### `hrStatus` [in]

A success or failure code indicating the status of the event. This value is returned by the event's [IMFMediaEvent::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getstatus) method.

### `pvValue` [in]

Pointer to a **PROPVARIANT** that contains the event value. This parameter can be **NULL**. This value is returned by the event's [IMFMediaEvent::GetValue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getvalue) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The object was shut down. |

## See also

[IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)