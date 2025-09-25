# MFCreateSourceReaderFromByteStream function

## Description

Creates the source reader from a byte stream.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. This byte stream will provide the source data for the source reader.

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this parameter to configure the source reader. For more information, see [Source Reader Attributes](https://learn.microsoft.com/windows/desktop/medfound/source-reader-attributes). This parameter can be **NULL**.

### `ppSourceReader` [out]

Receives a pointer to the [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call **CoInitialize(Ex)** and [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) before calling this function.

Internally, the source reader calls the [IMFSourceResolver::CreateObjectFromByteStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-createobjectfrombytestream) method to create a media source from the byte stream. Therefore, a byte-stream handler must be registered for the byte stream. For more information about byte-stream handlers, see [Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers).

This function is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)