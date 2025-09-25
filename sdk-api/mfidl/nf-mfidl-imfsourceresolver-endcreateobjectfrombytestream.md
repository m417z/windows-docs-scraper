# IMFSourceResolver::EndCreateObjectFromByteStream

## Description

Completes an asynchronous request to create a media source from a byte stream.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `pObjectType` [out]

Receives a member of the [MF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_object_type) enumeration, specifying the type of object that was created.

### `ppObject` [out]

Receives a pointer to the media source's **IUnknown** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_ABORT** | The application canceled the operation. |

## Remarks

Call this method from inside your application's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)