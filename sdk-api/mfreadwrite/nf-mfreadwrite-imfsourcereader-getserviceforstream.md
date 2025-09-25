# IMFSourceReader::GetServiceForStream

## Description

Queries the underlying media source or decoder for an interface.

## Parameters

### `dwStreamIndex` [in]

The stream or object to query. If the value is **MF_SOURCE_READER_MEDIASOURCE**, the method queries the media source. Otherwise, it queries the decoder that is associated with the specified stream. The following values are possible.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |
| ****MF_SOURCE_READER_MEDIASOURCE****<br><br>0xFFFFFFFF | The media source. |

### `guidService` [in]

A service identifier GUID. If the value is **GUID_NULL**, the method calls **QueryInterface** to get the requested interface. Otherwise, the method calls the [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) method. For a list of service identifiers, see [Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces).

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)