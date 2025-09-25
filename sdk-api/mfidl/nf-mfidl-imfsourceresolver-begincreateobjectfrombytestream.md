# IMFSourceResolver::BeginCreateObjectFromByteStream

## Description

Begins an asynchronous request to create a media source from a byte stream.

## Parameters

### `pByteStream` [in]

A pointer to the byte stream's [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface.

### `pwszURL` [in]

A null-terminated string that contains the original URL of the byte stream. This parameter can be **NULL**.

### `dwFlags` [in]

A bitwise **OR** of one or more flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).

### `pProps` [in]

A pointer to the **IPropertyStore** interface of a property store. The method passes the property store to the byte-stream handler. The byte-stream handler can use the property store to configure the media source. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `ppIUnknownCancelCookie` [out]

Receives an **IUnknown** pointer or the value **NULL**. If the value is not **NULL**, you can cancel the asynchronous operation by passing this pointer to the [IMFSourceResolver::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-cancelobjectcreation) method. The caller must release the interface. This parameter can be **NULL**.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SOURCERESOLVER_MUTUALLY_EXCLUSIVE_FLAGS** | The *dwFlags* parameter contains mutually exclusive flags. |
| **MF_E_UNSUPPORTED_BYTESTREAM_TYPE** | The byte stream is not supported. |
| **MF_E_BYTESTREAM_NOT_SEEKABLE** | The byte stream does not support seeking. |

## Remarks

The *dwFlags* parameter must contain the **MF_RESOLUTION_MEDIASOURCE** flag and should not contain the **MF_RESOLUTION_BYTESTREAM** flag.

The source resolver attempts to find one or more byte-stream handlers for the byte stream, based on the file name extension of the URL, or the MIME type of the byte stream (or both). The URL is specified in the optional *pwszURL* parameter, and the MIME type may be specified in the [MF_BYTESTREAM_CONTENT_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestream-content-type-attribute) attribute on the byte stream. Byte-stream handlers are registered by file name extension or MIME type, or both, as described in [Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers). The caller should specify at least one of these values.

When the operation completes, the source resolver calls the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The **Invoke** method should call [IMFSourceResolver::EndCreateObjectFromByteStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-endcreateobjectfrombytestream) to get a pointer to the media source.

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)