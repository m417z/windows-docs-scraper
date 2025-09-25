# IMFByteStreamHandler::BeginCreateObject

## Description

Begins an asynchronous request to create a media source from a byte stream.

## Parameters

### `pByteStream` [in]

Pointer to the byte stream's [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface.

### `pwszURL` [in]

String that contains the original URL of the byte stream. This parameter can be **NULL**.

### `dwFlags` [in]

Bitwise OR of zero or more flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).

### `pProps` [in]

Pointer to the **IPropertyStore** interface of a property store. The byte-stream handler can use this property store to configure the object. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `ppIUnknownCancelCookie` [out]

Receives an **IUnknown** pointer or the value **NULL**. If the value is not **NULL**, you can cancel the asynchronous operation by passing this pointer to the [IMFByteStreamHandler::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamhandler-cancelobjectcreation) method. The caller must release the interface. This parameter can be **NULL**.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CANNOT_PARSE_BYTESTREAM** | Unable to parse the byte stream. |

## Remarks

The *dwFlags* parameter must contain the MF_RESOLUTION_MEDIASOURCE flag and should not contain the MF_RESOLUTION_BYTESTREAM flag.

The byte-stream handler is responsible for parsing the stream and validating the contents. If the stream is not valid or the byte stream handler cannot parse the stream, the handler should return a failure code. The byte stream is not guaranteed to match the type of stream that the byte handler is designed to parse.

If the *pwszURL* parameter is not **NULL**, the byte-stream handler might use the URL during the resolution process. (For example, it might use the file name extension, if present.) Also, the byte stream might contain the [MF_BYTESTREAM_CONTENT_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestream-content-type-attribute) attribute, specifying the MIME type.

When the operation completes, the byte-stream handler calls the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The **Invoke** method should call [IMFByteStreamHandler::EndCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamhandler-endcreateobject) to get a pointer to the media source.

## See also

[IMFByteStreamHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamhandler)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)