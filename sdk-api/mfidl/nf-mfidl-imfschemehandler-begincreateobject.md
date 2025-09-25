# IMFSchemeHandler::BeginCreateObject

## Description

Begins an asynchronous request to create an object from a URL.

When the [Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver) creates a media source from a URL, it passes the request to a scheme handler. The scheme handler might create a media source directly from the URL, or it might return a byte stream. If it returns a byte stream, the source resolver use a byte-stream handler to create the media source from the byte stream.

## Parameters

### `pwszURL` [in]

A null-terminated string that contains the URL to resolve.

### `dwFlags` [in]

A bitwise **OR** of one or more flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).

### `pProps` [in]

A pointer to the **IPropertyStore** interface of a property store. The scheme handler can use this property store to configure the object. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `ppIUnknownCancelCookie` [out]

Receives an **IUnknown** pointer or the value **NULL**. If the value is not **NULL**, you can cancel the asynchronous operation by passing this pointer to the [IMFSchemeHandler::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-cancelobjectcreation) method. The caller must release the interface. This parameter can be **NULL**, in which case the **IUnknown** pointer is not returned to the caller.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_ACCESSDENIED** | Cannot open the URL with the requested access (read or write). |
| **MF_E_UNSUPPORTED_BYTESTREAM_TYPE** | Unsupported byte stream type. |

## Remarks

The *dwFlags* parameter must contain the **MF_RESOLUTION_MEDIASOURCE** flag or the **MF_RESOLUTION_BYTESTREAM** flag. If the **MF_RESOLUTION_MEDIASOURCE** flag is set, the scheme handler might create the media source directly from the URL, or it might create a byte stream. The type of object is returned in the *pObjectType* parameter of the [IMFSchemeHandler::EndCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-endcreateobject) method. If the scheme handler returns a byte stream, the source resolver will pass the byte stream to a byte-stream handler, which will create the media source from the byte stream.

If the **MF_RESOLUTION_BYTESTREAM** flag is set, the scheme handler will attempt to create a byte stream from the URL. However, if the scheme handler is designed to create a media source directly, rather than a byte stream, the method will fail.

The following table summarizes the behavior of these two flags when passed to this method:

| Flag | Object created |
| --- | --- |
| **MF_RESOLUTION_MEDIASOURCE** | Media source or byte stream |
| **MF_RESOLUTION_BYTESTREAM** | Byte stream |

The **MF_RESOLUTION_MEDIASOURCE** and **MF_RESOLUTION_BYTESTREAM** flags can be combined, although in this case it is redundant.

When the operation completes, the scheme handler calls the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The Invoke method should call [IMFSchemeHandler::EndCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-endcreateobject) to get a pointer to the created object.

## See also

[IMFSchemeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfschemehandler)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)