# MFCreateSinkWriterFromMediaSink function

## Description

Creates the sink writer from a media sink.

## Parameters

### `pMediaSink` [in]

Pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface of a media sink.

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this parameter to configure the sink writer. For more information, see [Sink Writer Attributes](https://learn.microsoft.com/windows/desktop/medfound/sink-writer-attributes). This parameter can be **NULL**.

### `ppSinkWriter` [out]

Receives a pointer to the [IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call **CoInitialize(Ex)** and [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) before calling this function.

When you are done using the media sink, call the media sink's [IMFMediaSink::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method. (The sink writer does not shut down the media sink.) Release the sink writer before calling **Shutdown** on the media sink.

This function is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)