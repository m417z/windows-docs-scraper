# IMFSourceResolver::CreateObjectFromByteStream

## Description

Creates a media source from a byte stream. This method is synchronous.

## Parameters

### `pByteStream` [in]

Pointer to the byte stream's [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface.

### `pwszURL` [in]

Null-terminated string that contains the URL of the byte stream. The URL is optional and can be **NULL**. See Remarks for more information.

### `dwFlags` [in]

Bitwise **OR** of flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).

### `pProps` [in]

Pointer to the **IPropertyStore** interface of a property store. The method passes the property store to the byte-stream handler. The byte-stream handler can use the property store to configure the media source. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `pObjectType` [out]

Receives a member of the [MF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_object_type) enumeration, specifying the type of object that was created.

### `ppObject` [out]

Receives a pointer to the media source's **IUnknown** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SOURCERESOLVER_MUTUALLY_EXCLUSIVE_FLAGS** | The *dwFlags* parameter contains mutually exclusive flags. |
| **MF_E_UNSUPPORTED_BYTESTREAM_TYPE** | This byte stream is not supported. |

## Remarks

The *dwFlags* parameter must contain the **MF_RESOLUTION_MEDIASOURCE** flag and should not contain the **MF_RESOLUTION_BYTESTREAM** flag.

The source resolver attempts to find one or more byte-stream handlers for the byte stream, based on the file name extension of the URL, or the MIME type of the byte stream (or both). The URL is specified in the optional *pwszURL* parameter, and the MIME type may be specified in the [MF_BYTESTREAM_CONTENT_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestream-content-type-attribute) attribute on the byte stream. Byte-stream handlers are registered by file name extension or MIME type, or both, as described in [Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers). The caller should specify at least one of these values (both if possible):

* Specify the URL in the *pwszURL* parameter.
* Specify the MIME type by setting the [MF_BYTESTREAM_CONTENT_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestream-content-type-attribute) attribute on the byte stream. (This attribute might be set already when you create the byte stream, depending on how the byte stream was created.)

**Note** This method cannot be called remotely.

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)