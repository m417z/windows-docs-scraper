# IMFSourceResolver::BeginCreateObjectFromURL

## Description

Begins an asynchronous request to create a media source or a byte stream from a URL.

## Parameters

### `pwszURL` [in]

Null-terminated string that contains the URL to resolve.

### `dwFlags` [in]

Bitwise OR of flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).

### `pProps` [in]

Pointer to the **IPropertyStore** interface of a property store. The method passes the property store to the scheme handler or byte-stream handler that creates the object. The handler can use the property store to configure the object. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `ppIUnknownCancelCookie` [out]

Receives an **IUnknown** pointer or the value **NULL**. If the value is not **NULL**, you can cancel the asynchronous operation by passing this pointer to the [IMFSourceResolver::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-cancelobjectcreation) method. The caller must release the interface. This parameter can be **NULL**.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SOURCERESOLVER_MUTUALLY_EXCLUSIVE_FLAGS** | The *dwFlags* parameter contains mutually exclusive flags. |
| **MF_E_UNSUPPORTED_SCHEME** | The URL scheme is not supported. |

## Remarks

The *dwFlags* parameter must contain either the MF_RESOLUTION_MEDIASOURCE flag or the MF_RESOLUTION_BYTESTREAM flag, but should not contain both.

For local files, you can pass the file name in the *pwszURL* parameter; the `file:` scheme is not required.

When the operation completes, the source resolver calls the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The **Invoke** method should call [IMFSourceResolver::EndCreateObjectFromURL](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-endcreateobjectfromurl) to get a pointer to the object that was created.

The usage of the *pProps* parameter depends on the implementation of the media source.

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)