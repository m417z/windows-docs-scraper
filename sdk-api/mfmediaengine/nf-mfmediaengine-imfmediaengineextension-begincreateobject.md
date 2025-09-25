# IMFMediaEngineExtension::BeginCreateObject

## Description

Begins an asynchronous request to create either a byte stream or a media source.

## Parameters

### `bstrURL` [in]

The URL of the media resource.

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface.

If the *type* parameter equals **MF_OBJECT_BYTESTREAM**, this parameter is **NULL**.

If *type* equals **MF_OBJECT_MEDIASOURCE**, this parameter either contains a pointer to a byte stream or is **NULL**. See Remarks for more information.

### `type` [in]

A member of the [MF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_object_type) enumeration that specifies which type of object to create.

| Value | Meaning |
| --- | --- |
| **MF_OBJECT_BYTESTREAM** | Create a byte stream. The byte stream must support the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface. |
| **MF_OBJECT_MEDIASOURCE** | Create a media source. The media source must support the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface. |

### `ppIUnknownCancelCookie` [out]

Receives a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. This pointer can be used to cancel the asynchronous operation, by passing the pointer to the [IMFMediaEngineExtension::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-cancelobjectcreation) method.

The caller must release the interface. This parameter can be NULL.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface. This interface is used to signal the completion of the asynchronous operation.

### `punkState` [in, optional]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of an object implemented by the caller. You can use this object to hold state information for the callback. The object is returned to the caller when the callback is invoked. This parameter can be **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method requests the object to create either a byte stream or a media source, depending on the value of the *type* parameter:

* If *type* is **MF_OBJECT_BYTESTREAM**, the method creates a byte stream for the URL that is specified in *bstrURL*. In this case, the *pByteStream* parameter is **NULL**.
* If *type* is **MF_OBJECT_MEDIASOURCE**, the method creates a media source, using the byte stream that is specified in the *pByteStream* parameter. Note that *pByteStream* can also be **NULL** in this case.

The method is performed asynchronously. The Media Engine calls the [IMFMediaEngineExtension::EndCreateObject](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-endcreateobject) method to complete the operation.

### Implementation Notes

A Media Engine extension can be used to support a custom byte stream object, a custom media source, or both. For a byte stream, create the byte stream object when *type* equals **MF_OBJECT_BYTESTREAM**. For a media source, create the source when the type equals **MF_OBJECT_MEDIASOURCE**.

To load a URL, the Media Engine performs the following steps:

1. Try to create a byte stream from the URL.
2. If a byte stream is successfully created, try to create a media source from the byte stream.
3. If a byte stream cannot be created, try to create a media source directly from the URL.

At each step, the Media Engine calls **IMFMediaEngineExtension::BeginCreateObject** on the extension object. If the **BeginCreateObject** method fails, the Media Engine tries the [Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver).

In your **BeginCreateObject** method, you can choose to handle any of the following cases:

* The *type* parameter is **MF_OBJECT_BYTESTREAM**. Create a byte stream from the URL.
* The *type* parameter is **MF_OBJECT_MEDIASOURCE** and *pByteStream* points to a byte stream. Use the byte stream to create a media source.
* The *type* parameter is **MF_OBJECT_MEDIASOURCE** and *pByteStream* is **NULL**. Create a media source from the URL.

Return a failure code for any cases that you do not handle.

Examples:

* To support a custom media format, implement a media source. If the media source does not require any special byte-stream implementation, create the media source when *type* is **MF_OBJECT_MEDIASOURCE** and *pByteStream* is non-**NULL**. The standard Microsoft Media Foundation byte stream implementation will be used in this case.
* To support a custom URL scheme, handle the case where *type* is **MF_OBJECT_BYTESTREAM** and return a byte stream object that is capable of reading the URL.

If the **BeginCreateObject** method succeeds, the operation should be performed asynchronously. When the operation completes, call the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method on the callback interface specified in *pCallback*. The Media Engine completes the operation by calling [IMFMediaEngineExtension::EndCreateObject](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-endcreateobject).

## See also

[IMFMediaEngineExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineextension)