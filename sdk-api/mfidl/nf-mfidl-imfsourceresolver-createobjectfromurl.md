# IMFSourceResolver::CreateObjectFromURL

## Description

Creates a media source or a byte stream from a URL. This method is synchronous.

## Parameters

### `pwszURL` [in]

Null-terminated string that contains the URL to resolve.

### `dwFlags` [in]

Bitwise OR of one or more flags. See [Source Resolver Flags](https://learn.microsoft.com/windows/desktop/medfound/source-resolver-flags).
See remarks below.

### `pProps` [in]

Pointer to the **IPropertyStore** interface of a property store. The method passes the property store to the scheme handler or byte-stream handler that creates the object. The handler can use the property store to configure the object. This parameter can be **NULL**. For more information, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source).

### `pObjectType` [out]

Receives a member of the [MF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_object_type) enumeration, specifying the type of object that was created.

### `ppObject` [out]

Receives a pointer to the object's **IUnknown** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SOURCERESOLVER_MUTUALLY_EXCLUSIVE_FLAGS** | The *dwFlags* parameter contains mutually exclusive flags. |
| **MF_E_UNSUPPORTED_SCHEME** | The URL scheme is not supported. |

## Remarks

The *dwFlags* parameter must contain either the **MF_RESOLUTION_MEDIASOURCE** flag or the **MF_RESOLUTION_BYTESTREAM** flag, but should not contain both.

It is recommended that you do not set **MF_RESOLUTION_WRITE** on the input argument *dwFlags* unless it is necessary for your scenario. For most use-cases, media sources do not need to be created with write capability. Creating a media source with write capability may have a lower probability of success than creating a media source without write capability. This is because there can be stricter checks on the content represented by the URL when creating a media source with write capability.

For local files, you can pass the file name in the *pwszURL* parameter; the `file:` scheme is not required.

**Note** This method cannot be called remotely.

#### Examples

```cpp
//  Create a media source from a URL.
HRESULT CreateMediaSource(PCWSTR sURL, IMFMediaSource **ppSource)
{
    MF_OBJECT_TYPE ObjectType = MF_OBJECT_INVALID;

    IMFSourceResolver* pSourceResolver = NULL;
    IUnknown* pSource = NULL;

    // Create the source resolver.
    HRESULT hr = MFCreateSourceResolver(&pSourceResolver);
    if (FAILED(hr))
    {
        goto done;
    }

    // Use the source resolver to create the media source.

    // Note: For simplicity this sample uses the synchronous method to create
    // the media source. However, creating a media source can take a noticeable
    // amount of time, especially for a network source. For a more responsive
    // UI, use the asynchronous BeginCreateObjectFromURL method.

    hr = pSourceResolver->CreateObjectFromURL(
        sURL,                       // URL of the source.
        MF_RESOLUTION_MEDIASOURCE,  // Create a source object.
        NULL,                       // Optional property store.
        &ObjectType,        // Receives the created object type.
        &pSource            // Receives a pointer to the media source.
        );
    if (FAILED(hr))
    {
        goto done;
    }

    // Get the IMFMediaSource interface from the media source.
    hr = pSource->QueryInterface(IID_PPV_ARGS(ppSource));

done:
    SafeRelease(&pSourceResolver);
    SafeRelease(&pSource);
    return hr;
}

```

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)