# MFRegisterLocalSchemeHandler function

## Description

Registers a scheme handler in the caller's process.

## Parameters

### `szScheme` [in]

A string that contains the scheme. The scheme includes the trailing ':' character; for example,
"http:".

### `pActivate` [in]

A pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of an activation
object. The caller implements this interface. The
[IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject)
method of the activation object must create a scheme handler object. The scheme handler exposes the
[IMFSchemeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfschemehandler) interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Scheme handlers are used in Microsoft Media Foundation during the source resolution process, which creates a media
source from a URL. For more information, see
[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers).

Within a process, local scheme handlers take precedence over scheme handlers that are registered in the
registry. Local scheme handlers are not visible to other processes.

Use this function if you want to register a custom scheme handler for your application, but do not want the
handler available to other applications.

## See also

[MFRegisterLocalByteStreamHandler](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfregisterlocalbytestreamhandler)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)