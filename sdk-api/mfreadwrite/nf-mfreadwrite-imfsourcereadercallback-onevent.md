# IMFSourceReaderCallback::OnEvent

## Description

Called when the source reader receives certain events from the media source.

## Parameters

### `dwStreamIndex` [in]

For stream events, the value is the zero-based index of the stream that sent the event. For source events, the value is **MF_SOURCE_READER_MEDIASOURCE**.

### `pEvent` [in]

A pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of the event.

## Return value

Returns an **HRESULT** value. Currently, the source reader ignores the return value.

## Remarks

In the current implementation, the source reader uses this method to forward the following events to the application:

* [MEBufferingStarted](https://learn.microsoft.com/windows/desktop/medfound/mebufferingstarted)
* [MEBufferingStopped](https://learn.microsoft.com/windows/desktop/medfound/mebufferingstopped)
* [MEConnectEnd](https://learn.microsoft.com/windows/desktop/medfound/meconnectend)
* [MEConnectStart](https://learn.microsoft.com/windows/desktop/medfound/meconnectstart)
* [MEExtendedType](https://learn.microsoft.com/windows/desktop/medfound/meextendedtype)
* [MESourceCharacteristicsChanged](https://learn.microsoft.com/windows/desktop/medfound/mesourcecharacteristicschanged)
* [MESourceMetadataChanged](https://learn.microsoft.com/windows/desktop/medfound/mesourcemetadatachanged)

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReaderCallback](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereadercallback)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)