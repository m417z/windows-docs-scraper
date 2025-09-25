# MFRegisterLocalByteStreamHandler function

## Description

Registers a byte-stream handler in the caller's process.

## Parameters

### `szFileExtension` [in]

A string that contains the file name extension for this handler.

### `szMimeType` [in]

A string that contains the MIME type for this handler.

### `pActivate` [in]

A pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of an activation object. The caller implements this interface. The [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) method of the activation object must create a byte-stream handler. The byte-stream handler exposes the [IMFByteStreamHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamhandler) interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Byte-stream handlers are used in Microsoft Media Foundation during the source resolution process, which creates a media source from a URL. For more information, see [Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers).

Within a process, local byte-stream handlers take precedence over byte-stream handlers that are registered in the registry. Local byte-stream handlers are not visible to other processes.

Use this function if you want to register a custom byte-stream handler for your application, but do not want the handler available to other applications.

Either *szFileExtension* or *szMimeType* can be **NULL**; at least one must be non-**NULL**.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)